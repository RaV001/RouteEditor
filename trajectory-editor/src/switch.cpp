#include "switch.h"

Switch::Switch()
    : FwdPositiveTraj(nullptr)
    , FwdNegativeTraj(nullptr)
    , BwdPositiveTraj(nullptr)
    , BwdNegativeTraj(nullptr)
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
