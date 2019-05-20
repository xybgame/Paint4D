#include "painteditor.h"

PaintEditor::PaintEditor(QWidget *parent)
    : QOpenGLWidget (parent)
{
    //event赋值
    e.idcanvas  =&this->idcanvas;
    e.canvas    =&this->canvas  ;
    e.w         =(float)this->width();
    e.h         =(float)this->height();

    //执行组件初始化添加
    {
        ComponentCanvas         *drawcanvas=new ComponentCanvas();
        com.append(drawcanvas);
        ComponentCanvasControl *control=new ComponentCanvasControl();
        com.append(control);
    }
}

void PaintEditor::initializeGL  ()
{
    initializeOpenGLFunctions();
    glViewport  (0,0,width(),height());
    glClearColor(0,0,0,1);
    glEnable    (GL_DEPTH_TEST);
    glClear     (GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_Init(e);
        }
    }

}
void PaintEditor::paintGL       ()
{
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_Update(e);
        }
    }
}
void PaintEditor::resizeGL      (int w, int h)
{
    e.w         =(float)w;
    e.h         =(float)h;
    glViewport  (0,0,w,h);
    glClear     (GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_Resize(e);
        }
    }
}

void PaintEditor::mousePressEvent       (QMouseEvent *event)
{
    e.mouseevent=event;
    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_MousePress(e);
        }
    }
    this->update();
}
void PaintEditor::mouseReleaseEvent     (QMouseEvent *event)
{
    e.mouseevent=event;
    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_MouseRelease(e);
        }
    }
    this->update();
}
void PaintEditor::mouseMoveEvent        (QMouseEvent *event)
{
    e.mouseevent=event;
    e.x=event           ->x();
    e.y=height()-event  ->y();

    /*执行Component*/
    {
        uint i=0;
        uint length=com.length();
        for (; i < length; ++i)
        {
            com.value(i)->xyb_MouseMove(e);
        }
    }
    this->update();
}
