#ifndef COMPONENTPEN_H
#define COMPONENTPEN_H

#include "component.h"

class ComponentPen:public Component
{
public:
    ComponentPen();

    // Component interface
public:
    void xyb_Init           (XYBEvent &e)XYB_UNUSED
    void xyb_Update         (XYBEvent &e)XYB_UNUSED
    void xyb_Resize         (XYBEvent &e)XYB_UNUSED
    void xyb_MouseMove      (XYBEvent &e);
    void xyb_MousePress     (XYBEvent &e)XYB_UNUSED
    void xyb_MouseRelease   (XYBEvent &e)XYB_UNUSED
    void xyb_KeyPress       (XYBEvent &e)XYB_UNUSED
    void xyb_KeyRelease     (XYBEvent &e)XYB_UNUSED
};

#endif // COMPONENTPEN_H
