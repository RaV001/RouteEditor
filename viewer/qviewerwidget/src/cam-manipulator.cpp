#include    "cam-manipulator.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
CamManipulator::CamManipulator(settings_t settings, QObject *parent)
    : AbstractManipulator(parent)
    , settings(settings)
    , rel_pos(osg::Vec3f(settings.ext_cam_init_shift,
                         settings.ext_cam_init_height,
                         settings.ext_cam_init_dist))
    , angle_H(static_cast<double>(osg::DegreesToRadians(settings.ext_cam_init_angle_H)))
    , angle_V(static_cast<double>(osg::DegreesToRadians(settings.ext_cam_init_angle_V)))
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
osg::Matrixd CamManipulator::getMatrix() const
{
    osg::Matrix matrix;

    matrix *= osg::Matrix::translate(rel_pos);
    matrix *= osg::Matrix::rotate(osg::PI_2 - angle_V, osg::X_AXIS);
    matrix *= osg::Matrix::rotate(angle_H, osg::Z_AXIS);

    return matrix;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
osg::Matrixd CamManipulator::getInverseMatrix() const
{
    osg::Matrix invMatrix = osg::Matrix::inverse(getMatrix());



    return invMatrix;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool CamManipulator::performMovementRightMouseButton(const double eventTimeDelta,
                                                       const double dx,
                                                       const double dy)
{
    Q_UNUSED(eventTimeDelta)

    double k1 = static_cast<double>(settings.ext_cam_rot_coeff);

    angle_H += k1 * dx;
    angle_V += k1 * dy;

    return false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool CamManipulator::handleMouseWheel(const osgGA::GUIEventAdapter &ea,
                                        osgGA::GUIActionAdapter &aa)
{
    Q_UNUSED(aa)

    osgGA::GUIEventAdapter::ScrollingMotion sm = ea.getScrollingMotion();

    float speed = settings.ext_cam_speed;

    if ( (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_LEFT_SHIFT) ||
         (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_LEFT_SHIFT) )
    {
        speed = settings.ext_cam_speed_coeff * speed;
    }

    switch (sm)
    {
    case osgGA::GUIEventAdapter::SCROLL_UP:

        if (  (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_LEFT_CTRL) ||
              (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_RIGHT_CTRL))
        {
            rel_pos.y() -= speed * delta_time;
        }
        else
        {
            rel_pos.z() += speed * delta_time;
        }

        break;

    case osgGA::GUIEventAdapter::SCROLL_DOWN:

        if (  (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_LEFT_CTRL) ||
              (ea.getModKeyMask() == osgGA::GUIEventAdapter::MODKEY_RIGHT_CTRL))
        {
            rel_pos.y() += speed * delta_time;
        }
        else
        {
            rel_pos.z() -= speed * delta_time;
        }

        break;

    default:

        break;
    }

    if (rel_pos.z() <= settings.ext_cam_min_dist)
        rel_pos.z() = settings.ext_cam_min_dist;

    return false;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
bool CamManipulator::handleKeyDown(const osgGA::GUIEventAdapter &ea,
                                     osgGA::GUIActionAdapter &aa)
{
    Q_UNUSED(aa)
    /*nodes.push_back(osg::Vec3(3.75f, 0.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 100.0, 4.0));
    nodes.push_back(osg::Vec3(2.75f, 200.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 300.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 400.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 500.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 600.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 700.0, 0.0));
    nodes.push_back(osg::Vec3(2.75f, 800.0, 0.0));
    nodes.push_back(osg::Vec3(3.75f, 900.0, 0.0));*/
    switch (ea.getKey())
    {
    case osgGA::GUIEventAdapter::KEY_Left:

        rel_pos.x() -= settings.ext_cam_speed * delta_time;
        break;

    case osgGA::GUIEventAdapter::KEY_Right:

        rel_pos.x() += settings.ext_cam_speed * delta_time;
        break;

    case osgGA::GUIEventAdapter::KEY_Up:

        rel_pos.y() -= settings.ext_cam_speed * delta_time;
        break;

    case osgGA::GUIEventAdapter::KEY_Down:

        rel_pos.y() += settings.ext_cam_speed * delta_time;
        break;
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
CamManipulator::~CamManipulator()
{

}
