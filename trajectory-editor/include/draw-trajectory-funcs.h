#ifndef DRAWTRAJECTORYFUNCS_H
#define DRAWTRAJECTORYFUNCS_H

#include    <osg/Geode>
#include    <osg/Geometry>

 osg::ref_ptr<osg::Geode> drawLineTraj(const std::vector<osg::Vec3 *> nodes,
                                       osg::Vec4 color, float thickness, float height);

 osg::ref_ptr<osg::Geode> drawPyramid(osg::Vec3 node, osg::Vec3 node2,
                                      osg::Vec4 color, float thickness, float height);

#endif // DRAWTRAJECTORYFUNCS_H
