#include "DrawCommand.h"
#include <vizkit3d_debug_drawings/DrawingManager.h>
#include <osgViz/Object.h>
#include <boost/serialization/export.hpp>
namespace vizkit3dDebugDrawings
{
    
DrawCommand::DrawCommand(const std::string& drawingName) : Command(drawingName)
{
    
}


void DrawCommand::execute(DrawingManager* drawingManager) const
{
    drawingManager->addPrimitive(getDrawingName(), createPrimitive());
}

DrawCommand::~DrawCommand()
{
}

DrawCommand* DrawCommand::clone() const
{
    //should not be callable, but pure-virtual does not work with orogen.
    throw std::runtime_error("called DrawCommand clone()");
}


}

