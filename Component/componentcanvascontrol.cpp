#include "componentcanvascontrol.h"

ComponentCanvasControl::ComponentCanvasControl()
{
    id=QUuid::createUuid().toString();
    type="ComponentCanvasControl";
}

void ComponentCanvasControl::xyb_Init   (XYBEvent &e)
{
    x=y=z=begin_x=begin_y=0;
    sensitivity_rot=0.001f;
    sensitivity_trans=0.001f;
}
void ComponentCanvasControl::xyb_Update (XYBEvent &e)
{

}
void ComponentCanvasControl::xyb_Resize (XYBEvent &e)
{

}

void ComponentCanvasControl::xyb_MouseMove      (XYBEvent &e)
{
    switch (e.mouseevent->buttons())
    {
    case Qt::LeftButton:
        {
            float offset_x=begin_x-e.mouseevent->x();
            float offset_y=begin_y-e.mouseevent->y();
            x+=offset_x*sensitivity_rot;
            y+=offset_y*sensitivity_rot;
            e.idcanvas->rotx.xyb_SetRotX(y);
            e.idcanvas->roty.xyb_SetRotY(x);
        }
        break;
    case Qt::MidButton:
        {
            float offset_y=begin_y-e.mouseevent->y();
            z+=offset_y*sensitivity_trans;
            e.idcanvas->trans.xyb_SetTranslate(0,0,z);
        }
        break;
    }
}
void ComponentCanvasControl::xyb_MousePress     (XYBEvent &e)
{
    begin_x=e.mouseevent->x();
    begin_y=e.mouseevent->y();
}
void ComponentCanvasControl::xyb_MouseRelease   (XYBEvent &e)
{

}
