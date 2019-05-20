#include "componentcanvascontrol.h"

ComponentCanvasControl::ComponentCanvasControl()
{
    id=QUuid::createUuid().toString();
    type="ComponentCanvasControl";
}

void ComponentCanvasControl::xyb_Init   (XYBEvent &e)
{
    x=y=z=begin_x=begin_y=0;
    sensitivity_rot=0.0001f;
    sensitivity_trans=0.001f;
    is_alt=false;
}

void ComponentCanvasControl::xyb_MouseMove      (XYBEvent &e)
{
    switch (e.mouseevent->buttons())
    {
    case Qt::LeftButton:
        {
            if(is_alt==true)
            {
                float offset_x=begin_x-e.mouseevent->x();
                x+=offset_x*sensitivity_rot;
                e.canvas->roty.xyb_SetRotY(x);
                float offset_y=begin_y-e.mouseevent->y();
                y-=offset_y*sensitivity_rot;
                e.canvas->rotx.xyb_SetRotX(y);
            }
        }
        break;
    case Qt::MidButton:
        {
            float offset_y=begin_y-e.mouseevent->y();
            z+=offset_y*sensitivity_trans;
            e.canvas->trans.xyb_SetTranslate(0,0,z);
        }
        break;
    }
}
void ComponentCanvasControl::xyb_MousePress     (XYBEvent &e)
{
    begin_x=e.mouseevent->x();
    begin_y=e.mouseevent->y();
}

void ComponentCanvasControl::xyb_KeyPress       (XYBEvent &e)
{
    switch (e.keyevent->key())
    {
    case Qt::Key_F:
    {//清空位移，恢复初始状态
            x=y=z=begin_x=begin_y=0;
            e.canvas->rotx.xyb_SetRotX(0);
            e.canvas->roty.xyb_SetRotY(0);
            e.canvas->trans.xyb_SetTranslate(0,0,0);
    }
        break;
    case Qt::Key_Alt:
    {
        is_alt=true;
    }
        break;
    }
}
void ComponentCanvasControl::xyb_KeyRelease     (XYBEvent &e)
{
    switch (e.keyevent->key())
    {
    case Qt::Key_Alt:
    {
        is_alt=false;
    }
        break;
    }
}
