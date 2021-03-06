#pragma once
#include <string>
#include "Command.h"
#include <boost/serialization/base_object.hpp>

namespace vizkit3dDebugDrawings
{
    
/**A command that removes all content from a drawing but leaves the plugin loaded*/
class ClearDrawingCommand : public Command
{
    
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<Command>(*this);
    }
    
    
    
public:
    ClearDrawingCommand(const std::string& drawingName);   
    ClearDrawingCommand();
    virtual void execute(DrawingManager* drawingManager) const;    
    virtual ~ClearDrawingCommand();
    
    virtual ClearDrawingCommand* clone() const;
};
}
