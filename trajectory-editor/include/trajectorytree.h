#ifndef TRAJECTORYTREE_H
#define TRAJECTORYTREE_H

#include <QMap>
#include <QString>
#include "trajectory.h"

class TrajectoryTree
{
public:
    TrajectoryTree();
   ~TrajectoryTree();

    QMap<QString, Trajectory *> getTrajTree();

    void addTrajectory(QString name, Trajectory *traj);

private:
    QMap<QString, Trajectory *> traj_tree;



};

#endif // TRAJECTORYTREE_H
