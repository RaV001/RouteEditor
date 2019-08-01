#ifndef     MAINWINDOW_H
#define     MAINWINDOW_H

#include    <QMainWindow>
#include    <QSettings>

#include    "trajectory.h"

#include    "qviewerwidget.h"

#include    "abstract-loader.h"
#include    "scene-loader.h"

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

    Ui::MainWindow      *ui;

    QViewerWidget       *viewerWidget;

    osg::ref_ptr<osg::Group> root;

    QString             openPath;
    QString             savePath;
    QString             importPath;

    QSettings           *settings;

    Trajectory          *zds_traj1;
    Trajectory          *zds_traj2;

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
