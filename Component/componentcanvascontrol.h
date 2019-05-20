#ifndef COMPONENTCANVASCONTROL_H
#define COMPONENTCANVASCONTROL_H

#include "component.h"

class ComponentCanvasControl:public Component
{
public:
    ComponentCanvasControl();
private:
    float x,y,z;                                //xy实际的变化
    float begin_x,begin_y;                      //起始xy的值
    float sensitivity_rot,sensitivity_trans;    //灵敏度
    bool  is_alt;
    // Component interface
public:
    void xyb_Init           (XYBEvent &e);
    void xyb_Update         (XYBEvent &e)XYB_UNUSED
    void xyb_Resize         (XYBEvent &e)XYB_UNUSED
    void xyb_MouseMove      (XYBEvent &e);
    void xyb_MousePress     (XYBEvent &e);
    void xyb_MouseRelease   (XYBEvent &e)XYB_UNUSED
    void xyb_KeyPress       (XYBEvent &e);
    void xyb_KeyRelease     (XYBEvent &e);
};

#endif // COMPONENTCANVASCONTROL_H
