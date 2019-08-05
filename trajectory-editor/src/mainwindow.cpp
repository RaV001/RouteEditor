#include    "mainwindow.h"
#include    "ui_mainwindow.h"

#include    <QDir>
#include    <QFileDialog>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , viewerWidget(Q_NULLPTR)
  , root(Q_NULLPTR)
  , traj_tree1(Q_NULLPTR)
  , traj_tree2(Q_NULLPTR)
  , openPath("./")
  , savePath("./")
  , importPath("./")
  , settings(new QSettings)
  , view_dist(1000.0f)

{
    ui->setupUi(this);

    QGridLayout *layout = new QGridLayout;
    viewerWidget = new QViewerWidget(QRect(0, 0, ui->frame->width(), ui->frame->height()));
    layout->addWidget(viewerWidget);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    ui->frame->setLayout(layout);

    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::slotQuit);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::slotOpen);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::slotSave);
    connect(ui->actionImport_ZDS_route, &QAction::triggered, this, &MainWindow::slotImport);

    openPath = settings->value("openPath", QDir::homePath()).toString();
    savePath = settings->value("savePath", QDir::homePath()).toString();
    importPath = settings->value("importPath", QDir::homePath()).toString();

    startTimer(40);

    ui->actionOpen->setVisible(false); //временно, дабы не путаться при импорте)
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    ui->frame->update();

}

void MainWindow::timerEvent(QTimerEvent *)
{
    QMainWindow::update();
}

void MainWindow::clean()
{
    if(root.valid())
        for(size_t i = 0; i < viewerWidget->getScene()->getNumChildren(); ++i)
            viewerWidget->getScene()->removeChild(i);

    ui->listWidget->clear();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::slotQuit()
{
    QApplication::quit();
}

//------------------------------------------------------------------------------
//Обработчик загрузки маршрута с боковыми путями
//------------------------------------------------------------------------------
void MainWindow::slotOpen()
{
    QString path = QFileDialog::getExistingDirectory(Q_NULLPTR,
                                                     tr("Open route"),
                                                     openPath,
                                                     QFileDialog::Option::ReadOnly);
    if (path.isEmpty())
        return;

    openPath = path;
    settings->setValue("importPath", openPath);


}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void MainWindow::slotSave()
{

}

//------------------------------------------------------------------------------
//Обработчик загрузки исходного маршрута
//------------------------------------------------------------------------------
void MainWindow::slotImport()
{

    QString path = QFileDialog::getExistingDirectory(Q_NULLPTR,
                                                     tr("Import ZDS route"),
                                                     importPath,
                                                     QFileDialog::Option::ReadOnly);
    if (path.isEmpty())
        return;

    clean();    

    importPath = path;
    settings->setValue("importPath", importPath);

    Trajectory *zds_traj1 = new Trajectory();
    zds_traj1->load(path + QDir::separator() + ROUTE1 + ".trk");

    traj_tree1 = new TrajectoryTree();
    traj_tree1->addTrajectory(ROUTE1, zds_traj1);

    Trajectory *zds_traj2 = new Trajectory();
    zds_traj2->load(path + QDir::separator() + ROUTE2 + ".trk");

    traj_tree2 = new TrajectoryTree();
    traj_tree2->addTrajectory(ROUTE2, zds_traj2);

    RouteLoader *loader = new SceneLoader();

    connect(loader, SIGNAL(logMessage(QString, Qt::GlobalColor)), this, SLOT(slotLogMessage(QString, Qt::GlobalColor)));

    if(loader->load(importPath.toStdString(), view_dist))
    {
        root = loader->getRoot();

        viewerWidget->getScene()->addChild(root.get());
    }

    delete loader;

}

void MainWindow::slotLogMessage(QString msg, Qt::GlobalColor color)
{
    ui->listWidget->addItem(msg);

    for(size_t i = 0; i < ui->listWidget->count(); ++i)
        ui->listWidget->item(i)->setForeground(color);
}
