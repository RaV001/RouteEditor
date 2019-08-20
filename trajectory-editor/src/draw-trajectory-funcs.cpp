#include    "draw-trajectory-funcs.h"

osg::ref_ptr<osg::Geode> drawLineTraj(const std::vector<osg::Vec3 *> nodes)
{
   osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

   osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;

   for(size_t i = 0; i < nodes.size(); ++i)
   {
       vertices->push_back(osg::Vec3(nodes[i]->x(),nodes[i]->y(),nodes[i]->z()+5.f));

       colors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
   }

   osg::ref_ptr<osg::Geometry> quad = new osg::Geometry;
   quad->setVertexArray(vertices.get());

   quad->setColorArray(colors.get());

   quad->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, 0, nodes.size()));

   osg::ref_ptr<osg::Geode> root = new osg::Geode;
   root->addDrawable(quad.get());

   return root;

}

osg::ref_ptr<osg::Geode> drawPyramid(osg::Vec3 point1, osg::Vec3 point2, float thickness)
{
    osg::Vec3 a = osg::Vec3(point1.x(), point1.y(), point1.z() + thickness);
    osg::Vec3 b = osg::Vec3(point1.x() - thickness* sinf(30.f), point1.y(), point1.z() + thickness);
    osg::Vec3 c = osg::Vec3(point1.x(), point1.y(), point1.z() + thickness);

}
