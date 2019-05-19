#ifndef COMPONENTCANVASCONTROL_H
#define COMPONENTCANVASCONTROL_H

#include "component.h"

class ComponentCanvasControl:public Component
{
public:
    ComponentCanvasControl();
private:
    float x,y,z;              //xy实际的变化
    float begin_x,begin_y;  //起始xy的值
    float sensitivity_rot,sensitivity_trans;    //灵敏度
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
