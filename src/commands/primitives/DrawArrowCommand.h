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
class DrawArrowCommand : public DrawCommand
{
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        // serialize base class information
        ar & boost::serialization::base_object<DrawCommand>(*this);
        ar & position;
        ar & orientation;
        ar & scale;
        ar & colorRGBA;
    }
    
    
    
public:
    DrawArrowCommand();
    
    DrawArrowCommand(const std::string& drawingName, const base::Vector3d& position,
                     const base::Quaterniond& orientation, const base::Vector3d& scale,
                      const base::Vector4d& colorRGBA);
    
    virtual osg::ref_ptr<osgviz::Object> createPrimitive() const;
    
    virtual DrawArrowCommand* clone() const;
    
private:
    base::Vector3d position;
    base::Quaterniond orientation;
    base::Vector3d scale;
    base::Vector4d colorRGBA;

};
}
