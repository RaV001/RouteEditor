#ifndef     MAINWINDOW_H
#define     MAINWINDOW_H

#include    <QMainWindow>
#include    <QSettings>
#include    <QTreeWidget>

#include    "trajectory.h"

#include    "qviewerwidget.h"

#include    "abstract-loader.h"
#include    "scene-loader.h"
#include    "trajectorytree.h"
#include    "line-trajectory.h"

#include    "free-manipulator.h"
#include    "settings.h"
#include    "camera-switcher.h"
#include    "cam-manipulator.h"

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

    const QString ROUTE1;
    const QString ROUTE2;

    Ui::MainWindow      *ui;

    QViewerWidget       *viewerWidget;

    osg::ref_ptr<osg::Group> root;

    TrajectoryTree      *traj_tree1;
    TrajectoryTree      *traj_tree2;

    QString             openPath;
    QString             savePath;
    QString             importPath;

    QSettings           *settings;

    float               view_dist;

    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *);

    void clean();

private slots:

    void slotQuit();

    void slotOpen();

    void slotSave();

    void slotImport();

    void slotLogMessage(QString msg, Qt::GlobalColor color);

    void slotItemChanged();
};

#endif // MAINWINDOW_H
