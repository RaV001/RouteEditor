#include    "line-trajectory.h"

LineTrajectory::LineTrajectory(): root(new osg::Group)
{

}

LineTrajectory::~LineTrajectory()
{

}

osg::ref_ptr<osg::Group> LineTrajectory::drawLineTraj(const std::vector<osg::Vec3 *> nodes,
                                      osg::Vec4 color, float thickness, float height) const
{

   for(size_t i = 0; i < nodes.size() - 1; ++i)
   {

       osg::ref_ptr<osg::Geode> geode =  drawPyramid(*nodes[i], *nodes[i+1], color, thickness, height);

       root->addChild(geode.get());
   }

   return root;
}

void LineTrajectory::changeColor(osg::Vec4 color)
{

     for (size_t i = 0; i < root->getNumChildren(); ++i)
     {
       osg::ref_ptr<osg::Geode> geode = root->getChild(i)->asGeode();

       //osg::Geode* root3 = dynamic_cast<osg::Geode*>( root2.get());

       osg::ref_ptr<osg::Geometry> pyramid = dynamic_cast<osg::Geometry*> (geode->getDrawable(0));

       osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();
       colors->push_back(color);
       colors->push_back(color);
       colors->push_back(color);
       colors->push_back(color);
       colors->push_back(color);
       colors->push_back(color);

       pyramid->setColorArray(colors.get());
       pyramid->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

     }
}

osg::ref_ptr<osg::Geode> LineTrajectory::drawPyramid(osg::Vec3 node, osg::Vec3 node2,
                                     osg::Vec4 color, float thickness, float height) const
{
    const float rad = osg::DegreesToRadians(30.f); //0.523599f; //30 градусов в радианах

    node.z() += height;

    osg::Vec3 a = osg::Vec3(node.x(), node.y(), node.z() + thickness);
    osg::Vec3 b = osg::Vec3(node.x() - thickness * cosf(rad), node.y(), node.z() - thickness * sinf(rad));
    osg::Vec3 c = osg::Vec3(node.x() + thickness * cosf(rad), node.y(), node.z() - thickness * sinf(rad));

    node2.z() += height;

    osg::Vec3 a2 = osg::Vec3(node2.x(), node2.y(), node2.z() + thickness);
    osg::Vec3 b2 = osg::Vec3(node2.x() - thickness * cosf(rad), node2.y(), node2.z() - thickness * sinf(rad));
    osg::Vec3 c2 = osg::Vec3(node2.x() + thickness * cosf(rad), node2.y(), node2.z() - thickness * sinf(rad));

    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array();
    vertices->push_back(a);
    vertices->push_back(b);
    vertices->push_back(c);
    vertices->push_back(a2);
    vertices->push_back(b2);
    vertices->push_back(c2);
    vertices->resize(6);

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();
    colors->push_back(color);
    colors->push_back(color);
    colors->push_back(color);
    colors->push_back(color);
    colors->push_back(color);
    colors->push_back(color);

    osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_QUADS, 12);
    (*indices)[0] = 0; (*indices)[1] = 2; (*indices)[2] = 5; (*indices)[3] = 3;
    (*indices)[4] = 0; (*indices)[5] = 1; (*indices)[6] = 4; (*indices)[7] = 3;
    (*indices)[8] = 1; (*indices)[9] = 2; (*indices)[10] = 5; (*indices)[11] = 4;

    osg::ref_ptr<osg::Geometry> pyramid = new osg::Geometry;
    pyramid->setVertexArray(vertices.get());
    pyramid->setColorArray(colors.get());
    pyramid->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
    pyramid->addPrimitiveSet(indices.get());

    osg::ref_ptr<osg::Geode> root = new osg::Geode;
    root->addDrawable(pyramid.get());

    return root;
}
