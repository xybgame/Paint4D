#ifndef COMPONENTCANVAS_H
#define COMPONENTCANVAS_H

#include "component.h"

class ComponentCanvas:public Component
{
public:
    ComponentCanvas();

    // Component interface
public:
    void xyb_Init           (XYBEvent &e);
    void xyb_Update         (XYBEvent &e);
    void xyb_Resize         (XYBEvent &e);
    void xyb_MouseMove      (XYBEvent &e)XYB_UNUSED
    void xyb_MousePress     (XYBEvent &e)XYB_UNUSED
    void xyb_MouseRelease   (XYBEvent &e)XYB_UNUSED
    void xyb_KeyPress       (XYBEvent &e)XYB_UNUSED
    void xyb_KeyRelease     (XYBEvent &e)XYB_UNUSED
};

#endif // COMPONENTCANVAS_H
