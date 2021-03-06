#include "DrawCylinderCommand.h"
#include <osgViz/modules/viz/Primitives/PrimitivesFactory.h>
#include <osgViz/OsgViz.hpp>

namespace vizkit3dDebugDrawings
{
    
osg::ref_ptr< osgviz::Object > DrawCylinderCommand::createPrimitive() const
{
    osgviz::PrimitivesFactory* fac = osgviz::OsgViz::getInstance()->getModuleInstance<osgviz::PrimitivesFactory>("PrimitivesFactory");
    const osg::Vec4 color(colorRGBA[0], colorRGBA[1], colorRGBA[2], colorRGBA[3]);
    auto prim = fac->createShape(osgviz::PrimitivesFactory::CYLINDER, size.x(), size.y(), size.z());
    prim->setColor(colorRGBA[0], colorRGBA[1], colorRGBA[2], colorRGBA[3]);
    prim->setPosition(position.x(), position.y(), position.z());
    prim->setOrientation(orientation.x(), orientation.y(), orientation.z(), orientation.w());
    return prim;
}

DrawCylinderCommand::DrawCylinderCommand(const std::string& drawingName,
                                         const base::Vector3d& position,
                                         const base::Quaterniond& orientation,
                                         const base::Vector3d& size,
                                         const base::Vector4d& colorRGBA):
        DrawCommand(drawingName), position(position), orientation(orientation),
        size(size), colorRGBA(colorRGBA)
{}

DrawCylinderCommand::DrawCylinderCommand(): DrawCommand("default")
{}

DrawCylinderCommand* DrawCylinderCommand::clone() const
{
    return new DrawCylinderCommand(*this);
}

}

