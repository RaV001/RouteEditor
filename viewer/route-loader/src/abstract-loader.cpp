//------------------------------------------------------------------------------
//
//      Abstract loader or railway route
//      (c) maisvendoo, 03/12/2018
//
//------------------------------------------------------------------------------
/*!
 * \file
 * \brief Abstract loader or railway route
 * \copyright maisvendoo
 * \author maisvendoo
 * \date 03/12/2018
 */

#include    "abstract-loader.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
RouteLoader::RouteLoader()
    : routeDir("")
    , root(new osg::Group)
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
osg::Group *RouteLoader::getRoot()
{
    if (root.valid())
        return root.release();
    else
        return nullptr;
}
