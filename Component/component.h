#ifndef COMPONENT_H
#define COMPONENT_H

#include <QUuid>
#include "paintcanvas.h"

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
    virtual void xyb_Init           (XYBEvent &e){}
    virtual void xyb_Update         (XYBEvent &e){}
    virtual void xyb_Resize         (XYBEvent &e){}
    virtual void xyb_MouseMove      (XYBEvent &e){}
    virtual void xyb_MousePress     (XYBEvent &e){}
    virtual void xyb_MouseRelease   (XYBEvent &e){}
};

#endif // COMPONENT_H
