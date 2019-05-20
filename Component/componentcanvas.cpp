#include "componentcanvas.h"

ComponentCanvas::ComponentCanvas()
{
    id=QUuid::createUuid().toString();
    type="ComponentCanvas";
}

void ComponentCanvas::xyb_Init  (XYBEvent &e)
{
    e.canvas->xyb_Create("C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Model\\sphere.obj",
                      "C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Shader\\id.vsh",
                      "C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Shader\\id.fsh");
    e.canvas->xyb_InitGL();
}
void ComponentCanvas::xyb_Update(XYBEvent &e)
{
    e.canvas->xyb_UpdateGL(GL_LINE_LOOP);
}
void ComponentCanvas::xyb_Resize(XYBEvent &e)
{
    e.canvas->xyb_ResizeGL(e.w,e.h);
}
