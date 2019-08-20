#ifndef DRAWTRAJECTORYFUNCS_H
#define DRAWTRAJECTORYFUNCS_H

#include    <osg/Geode>
#include    <osg/Geometry>

 osg::ref_ptr<osg::Geode> drawLineTraj(const std::vector<osg::Vec3 *> nodes);

 osg::ref_ptr<osg::Geode> drawPyramid(osg::Vec3 point1, osg::Vec3 point2, float thickness);

#endif // DRAWTRAJECTORYFUNCS_H
