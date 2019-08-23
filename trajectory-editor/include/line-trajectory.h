#ifndef DRAWTRAJECTORYFUNCS_H
#define DRAWTRAJECTORYFUNCS_H

#include    <osg/Geode>
#include    <osg/Geometry>

class LineTrajectory
{
public:
    LineTrajectory();
    ~LineTrajectory();

    osg::ref_ptr<osg::Group> drawLineTraj(const std::vector<osg::Vec3 *> nodes,
                                           osg::Vec4 color, float thickness, float height) const;
    osg::ref_ptr<osg::Group> root;

    void changeColor(osg::Vec4 color);

private:

    osg::ref_ptr<osg::Geode> drawPyramid(osg::Vec3 node, osg::Vec3 node2,
                                         osg::Vec4 color, float thickness, float height) const;

};




#endif // DRAWTRAJECTORYFUNCS_H
