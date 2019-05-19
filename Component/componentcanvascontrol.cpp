#include "componentcanvascontrol.h"

ComponentCanvasControl::ComponentCanvasControl()
{
    id=QUuid::createUuid().toString();
    type="ComponentCanvasControl";
}

void ComponentCanvasControl::xyb_Init   (XYBEvent &e)
{

}
void ComponentCanvasControl::xyb_Update (XYBEvent &e)
{

}
void ComponentCanvasControl::xyb_Resize (XYBEvent &e)
{

}

void ComponentCanvasControl::xyb_MouseMove      (XYBEvent &e)
{
    e.idcanvas->rotx.xyb_SetRotX(e.x);
}
void ComponentCanvasControl::xyb_MousePress     (XYBEvent &e)
{

}
void ComponentCanvasControl::xyb_MouseRelease   (XYBEvent &e)
{

}
