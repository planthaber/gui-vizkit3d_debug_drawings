#pragma once
#include <vizkit3d_debug_drawings/commands/DrawCommand.h>
#include <string>
#include <base/Eigen.hpp>
#include <boost_serialization/EigenTypes.hpp>

namespace osg
{
    class Node;
}

namespace vizkit3dDebugDrawings
{
class DrawSphereCommand : public DrawCommand
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<DrawCommand>(*this);
        ar & position;
        ar & radius;
        ar & colorRGBA;
    }
    
    
    
public:
    DrawSphereCommand();
    
    DrawSphereCommand(const std::string& drawingName, const base::Vector3d& position, double radius,
                      const base::Vector4d& colorRGBA);
    
    virtual osg::ref_ptr<osgviz::Object> createPrimitive() const;
    
    virtual DrawSphereCommand* clone() const;
    
private:
    base::Vector3d position;
    double radius;
    base::Vector4d colorRGBA;

};
}
