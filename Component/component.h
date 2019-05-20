#ifndef COMPONENT_H
#define COMPONENT_H

#include "paintcanvas.h"

#define XYB_UNUSED {Q_UNUSED(e);}

class Component
{
public:
    QString id;
    QString type;
    Component()
    {
        id=QUuid::createUuid().toString();
        type="Component";
    }
public:
    virtual void xyb_Init           (XYBEvent &e)XYB_UNUSED
    virtual void xyb_Update         (XYBEvent &e)XYB_UNUSED
    virtual void xyb_Resize         (XYBEvent &e)XYB_UNUSED
    virtual void xyb_MouseMove      (XYBEvent &e)XYB_UNUSED
    virtual void xyb_MousePress     (XYBEvent &e)XYB_UNUSED
    virtual void xyb_MouseRelease   (XYBEvent &e)XYB_UNUSED
    virtual void xyb_KeyPress       (XYBEvent &e)XYB_UNUSED
    virtual void xyb_KeyRelease     (XYBEvent &e)XYB_UNUSED
};

#endif // COMPONENT_H
