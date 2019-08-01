#ifndef     MAINWINDOW_H
#define     MAINWINDOW_H

#include    <QMainWindow>
#include    <QSettings>

#include    "trajectory.h"

#include    "qviewerwidget.h"

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

    QString             openPath;
    QString             savePath;
    QString             importPath;

    QSettings           *settings;

    Trajectory          *zds_traj1;
    Trajectory          *zds_traj2;

    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *);

private slots:

    void slotQuit();

    void slotOpen();

    void slotSave();

    void slotImport();
};

#endif // MAINWINDOW_H
