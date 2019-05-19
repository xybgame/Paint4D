#ifndef COMPONENTCANVASCONTROL_H
#define COMPONENTCANVASCONTROL_H

#include "component.h"

class ComponentCanvasControl:public Component
{
public:
    ComponentCanvasControl();

    // Component interface
public:
    void xyb_Init           (XYBEvent &e);
    void xyb_Update         (XYBEvent &e);
    void xyb_Resize         (XYBEvent &e);
    void xyb_MouseMove      (XYBEvent &e);
    void xyb_MousePress     (XYBEvent &e);
    void xyb_MouseRelease   (XYBEvent &e);
};

#endif // COMPONENTCANVASCONTROL_H
