#include "painteditor.h"

PaintEditor::PaintEditor(QWidget *parent)
    : QOpenGLWidget (parent)
{
}

void PaintEditor::initializeGL  ()
{
    initializeOpenGLFunctions();
    glViewport(0,0,width(),height());
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    canvas.xyb_Create("C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Model\\sphere.obj",
                      "C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Shader\\base.vsh",
                      "C:\\Users\\xiangyubo\\Desktop\\Git\\Paint4D\\Shader\\base.fsh");
    canvas.xyb_InitGL();
}
void PaintEditor::paintGL       ()
{
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    canvas.trans.xyb_SetTranslate(0,0,10);
    canvas.xyb_UpdateGL(GL_TRIANGLES);
}
void PaintEditor::resizeGL      (int w, int h)
{
    glViewport(0,0,w,h);
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    canvas.xyb_ResizeGL((float)w,(float)h);
}

void PaintEditor::mousePressEvent       (QMouseEvent *event)
{
}
void PaintEditor::mouseReleaseEvent     (QMouseEvent *event)
{
}
void PaintEditor::mouseMoveEvent        (QMouseEvent *event)
{
    e.x=event->x();
    e.y=height()-event->y();
    this->update();
}
