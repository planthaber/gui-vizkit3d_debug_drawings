#pragma once

/**This is the main header that should be included to use debug drawings.
 * It defines all required macros */

#ifndef ENABLE_DEBUG_DRAWINGS

    #define CONFIGURE_DEBUG_DRAWINGS_STANDALONE(...)  (void)0
    #define CONFIGURE_DEBUG_DRAWINGS_USE_EXISTING_WIDGET(...)  (void)0
    #define CONFIGURE_DEBUG_DRAWINGS_USE_PORT(...)  (void)0

    #define DRAW_RING(...) (void)0
    #define DRAW_PRIMITIVE(...) (void)0
    #define DRAW_WIREFRAME_BOX(...) (void) 0
    #define REMOVE_DRAWING(...) (void) 0
    #define CLEAR_DRAWING(...) (void) 0
    #define DRAW_SPHERE(...) (void)0
    #define DRAW_POLYLINE(...) (void)0
    #define DRAW_TEXT(...) (void)0
    #define DRAW_LINE(...) (void)0
    
    #define COMPLEX_DRAWING(...) (void)0
    
    
#else

//FIXME cleanup includes
#include <string>
#include "DrawingManager.h"
#include <osgViz/modules/viz/Primitives/PrimitivesFactory.h>
#include <osgViz/OsgViz.hpp>
#include <vector>
#include <base/Eigen.hpp>
#include "DebugDrawingColors.h"
#include <rtt/OutputPort.hpp>
#include <vizkit3d_debug_drawings/commands/Command.h>

namespace vizkit3d
{
    class Vizkit3DWidget;
}
/**
 *  *** Configuration ***
 *  Debug drawings need to be configured before beeing displayed.
 *  All drawings are buffered until configuration has taken place.
 *  Once configured the buffered drawings will be displayed and all further 
 *  drawings will be drawn immediately. 
 *  
 *  Following configurations are possible:
 *  * standalone:
 *    In standalone mode a qt application is created in a seperate thread.
 *    All drawings are displayed in a Vizkit3dWidget managed by that application.
 * 
 *  * using an existing vizkit3d widget:
 *    In this mode it is assumed that a qt application is already running and a
 *    Vizkit3dWidget exists somewhere. That widget is used to display all 
 *    drawings.
 * 
 *  * via rock ports:
 *    In this mode all drawing commands are sent through a rock port.
 *    A vizkit3d plugin can be used to display the drawings.
 * 
 * NOTE: Everything debug drawing related is thread local. I.e. debug drawings are
 *       configured on a per thread basis.
 */

    void CONFIGURE_DEBUG_DRAWINGS_STANDALONE();
    void CONFIGURE_DEBUG_DRAWINGS_USE_EXISTING_WIDGET(vizkit3d::Vizkit3DWidget* widget);
    void CONFIGURE_DEBUG_DRAWINGS_USE_PORT(RTT::OutputPort<vizkit3dDebugDrawings::Command>* port); 


    void DRAW_WIREFRAME_BOX(const std::string& drawingName, const base::Vector3d& position,
                            const base::Quaterniond& orientation, const base::Vector3d& size,
                            const base::Vector4d& colorRGBA);
    
    void DRAW_WIREFRAME_BOX(const std::string& drawingName, const base::Vector3d& position,
                            const base::Vector3d& size, const base::Vector4d& colorRGBA);
    
    /** @param position Position of the tip of the arrow
     *  @param orientation Identity points in z-direction*/
    void DRAW_ARROW(const std::string& drawingName, const base::Vector3d& position,
                    const base::Quaterniond& orientation, const base::Vector3d& scale,
                    const base::Vector4d& colorRGBA);
    
    void DRAW_ARROW(const std::string& drawingName, const base::Vector3d& position,
                    const base::Vector3d& scale, const base::Vector4d& colorRGBA);

    void DRAW_RING(const std::string& drawingName, const base::Vector3d& position,
                   const base::Quaterniond& orientation, double radius,
                   double height, double thickness, const base::Vector4d& colorRGBA);
    
    void DRAW_RING(const std::string& drawingName, const base::Vector3d& position,
                   double radius, double height, double thickness, const base::Vector4d& colorRGBA);
    
    void DRAW_SPHERE(const std::string& drawingName, double posX, double posY, double posZ,
                     double radius, const base::Vector4d& colorRGBA);
    
    void DRAW_SPHERE(const std::string& drawingName, const base::Vector3d& position,
                     double radius, const base::Vector4d& colorRGBA);
    
    /** @param position origin of the line
     *  @param points relative to @p position.*/
    void DRAW_POLYLINE(const std::string& drawingName, const base::Vector3d& position,
                       const std::vector<base::Vector3d>& points, const base::Vector4d& colorRGBA);
    
    /** @param points realtive to (0, 0, 0) */
    void DRAW_POLYLINE(const std::string& drawingName, const std::vector<base::Vector3d>& points,
                       const base::Vector4d& colorRGBA);
    
    /** @param from relative to (0, 0, 0)
     *  @param to   relative to (0, 0, 0) */
    void DRAW_LINE(const std::string& drawingName, const base::Vector3d& from, const base::Vector3d& to,
                   const base::Vector4d& colorRGBA);
    
    void DRAW_TEXT(const std::string& drawingName, const base::Vector3d& position,
                   const base::Quaterniond& orientation,
                   const std::string& text, double fontSize, const base::Vector4d& colorRGBA);
    
    void DRAW_TEXT(const std::string& drawingName, const base::Vector3d& position,
                   const std::string& text, double fontSize, const base::Vector4d& colorRGBA);
    
    void DRAW_TEXT(const std::string& drawingName, double posX, double posY, double posZ,
                   double rotW, double rotX, double rotY, double rotZ,
                   const std::string& text, double fontSize, const base::Vector4d& colorRGBA);
    
    void DRAW_TEXT(const std::string& drawingName, double posX, double posY, double posZ,
                   const std::string& text, double fontSize, const base::Vector4d& colorRGBA);
    
    /** Removes the drawing.
     * I.e. unloades the vizkit3d plugin responsible for rendering this drawing
     * @note If you want to animate something, use CLEAR_DRAWING instead.*/
    void REMOVE_DRAWING(const std::string& drawingName);
    
    /** Removes the content from a drawing but keeps the drawing itself.
     * I.e. the vizkit3d plugin will be kept and the users settings will be retained.
     * Use this if you want to animate movements.*/
    void CLEAR_DRAWING(const std::string& drawingName);
    
    /**Use this if debug drawings need additional code that is only required for the drawing */
    #define COMPLEX_DRAWING(...) do { __VA_ARGS__; } while (0)
    

#endif


