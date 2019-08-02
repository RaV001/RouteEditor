#include "switch.h"

Switch::Switch()
    : FwdPositiveTraj(Q_NULLPTR)
    , FwdNegativeTraj(Q_NULLPTR)
    , BwdPositiveTraj(Q_NULLPTR)
    , BwdNegativeTraj(Q_NULLPTR)
    , state("")
{

}

Switch::~Switch()
{

}

QString Switch::getState() const
{
    return state;
}

QString Switch::changeState()
{

}

Trajectory *Switch::getFwdPositiveTraj() const
{
    return FwdPositiveTraj;
}

Trajectory *Switch::getFwdNegativeTraj() const
{
    return  FwdNegativeTraj;
}

Trajectory *Switch::getBwdPositiveTraj() const
{
    return BwdPositiveTraj;
}

Trajectory *Switch::getBwdNegativeTraj() const
{
    return BwdNegativeTraj;
}
