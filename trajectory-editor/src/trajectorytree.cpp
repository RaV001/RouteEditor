#include "trajectorytree.h"

TrajectoryTree::TrajectoryTree()

{

}

TrajectoryTree::~TrajectoryTree()
{

}

QMap<QString, Trajectory *> TrajectoryTree::getTrajTree()
{
    return traj_tree;
}

void TrajectoryTree::addTrajectory(QString name, Trajectory *traj)
{
    traj_tree.insert(name, traj);
}

