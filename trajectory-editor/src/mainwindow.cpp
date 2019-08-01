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
  , openPath("./")
  , savePath("./")
  , importPath("./")
  , settings(new QSettings)
  , zds_traj1(Q_NULLPTR)
  , zds_traj2(Q_NULLPTR)
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
    //if(!root.valid())
        //return;
    for(size_t i = 0; i < viewerWidget->getScene()->getNumChildren(); ++i)
        viewerWidget->getScene()->removeChild(i);

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
    clean();

    QString path = QFileDialog::getExistingDirectory(Q_NULLPTR,
                                                     tr("Import ZDS route"),
                                                     importPath,
                                                     QFileDialog::Option::ReadOnly);

    if (path.isEmpty())
        return;

    importPath = path;
    settings->setValue("importPath", importPath);

    zds_traj1 = new Trajectory();
    zds_traj1->load(path + QDir::separator() + "route1.trk");

    zds_traj2 = new Trajectory();
    zds_traj2->load(path + QDir::separator() + "route2.trk");

    osg::ref_ptr<RouteLoader> loader = new SceneLoader();

    loader->load(importPath.toStdString(), 1000.0f);

    root = loader->getRoot();

    viewerWidget->getScene()->addChild(root.get());

}
