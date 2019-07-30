//------------------------------------------------------------------------------
//
//
//
//
//------------------------------------------------------------------------------

#ifndef     ABSTRACT_PATH_H
#define     ABSTRACT_PATH_H

#include    <osg/Referenced>
#include    <osg/Geometry>
#include    <QtGlobal>

#include    "basis.h"

#ifdef ROUTE_LOADER_LIB
    #define ROUTE_LOADER_EXPORT Q_DECL_EXPORT
#else
    #define ROUTE_LOADER_EXPORT Q_DECL_IMPORT
#endif

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class ROUTE_LOADER_EXPORT MotionPath : public osg::Referenced
{
public:

    MotionPath();

    virtual osg::Vec3 getPosition(float railway_coord) = 0;

    virtual osg::Vec3 getPosition(float railway_coord, osg::Vec3 &attitude) = 0;

    virtual osg::Vec3 getPosition(float railway_coord, osg::Vec3 &attitude, basis_t &basis) = 0;

    virtual osg::Vec3 getPosition(float railway_coord, basis_t &basis) = 0;

    float getLength() const;

protected:

    float length;
};

#endif // ABSTRACT_PATH_H
