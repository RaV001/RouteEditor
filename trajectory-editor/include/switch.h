#ifndef SWITCH_H
#define SWITCH_H

#include    "trajectory.h"

class Switch
{
public:
    Switch();
    ~Switch();

QString getState() const;

QString changeState();

Trajectory *getFwdPositiveTraj() const;
Trajectory *getFwdNegativeTraj() const;
Trajectory *getBwdPositiveTraj() const;
Trajectory *getBwdNegativeTraj() const;

private:

    QString state;

    Trajectory *FwdPositiveTraj;
    Trajectory *FwdNegativeTraj;
    Trajectory *BwdPositiveTraj;
    Trajectory *BwdNegativeTraj;

};

#endif // SWITCH_H
