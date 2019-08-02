#include "trajectorytree.h"

TrajectoryTree::TrajectoryTree()

{

}

TrajectoryTree::~TrajectoryTree()
{

}

QMap<QString, Trajectory *> TrajectoryTree::getTrajTree() const
{
    return traj_tree;
}

void TrajectoryTree::addTrajectory(const QString &name, Trajectory *traj)
{
    traj_tree.insert(name, traj);
}

