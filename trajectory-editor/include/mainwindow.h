#ifndef     MAINWINDOW_H
#define     MAINWINDOW_H

#include    <QMainWindow>
#include    <QSettings>

#include    "trajectory.h"

#include    "qviewerwidget.h"

#include    "abstract-loader.h"
#include    "scene-loader.h"
#include    "trajectorytree.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
namespace Ui
{
    class MainWindow;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:

    const QString ROUTE1 = "route1";
    const QString ROUTE2 = "route2";

    Ui::MainWindow      *ui;

    QViewerWidget       *viewerWidget;

    osg::ref_ptr<osg::Group> root;

    TrajectoryTree      *traj_tree1;
    TrajectoryTree      *traj_tree2;

    QString             openPath;
    QString             savePath;
    QString             importPath;

    QSettings           *settings;

    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *);

    void clean();

private slots:

    void slotQuit();

    void slotOpen();

    void slotSave();

    void slotImport();
};

#endif // MAINWINDOW_H
