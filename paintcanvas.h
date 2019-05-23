#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_4_Core>
#include <QImage>

#include "xybmodel.h"
#include "xybmath.h"

#define XYBOPENGL public QOpenGLFunctions_4_4_Core

class PaintCanvas:XYBOPENGL
{
private:
    QImage      *img;
    XYBMaterial material;
    XYBModel    model;
    GLuint      program,vertexbuffer;
    GLuint      pos,nor,uv;
    GLuint      mtrans,mpers,mrotx,mroty,mscale;
    GLuint      mtexture,tex;
public:
    XYBMatrix4x4 pers,trans,rotx,roty,scale;

    XYBTriangle *trianglelist;
public:
    void xyb_Create         (QString path, QString vspath, QString fspath);
    void xyb_CreateTexture  (QString path);
    void xyb_UpdateTexture  (float w,float h,float x,float y,uchar*data);
    void xyb_InitGL         ();
    void xyb_UpdateGL       (GLenum drawtype);
    void xyb_ResizeGL       (float w,float h);
};

//事件信息传递类
struct XYBEvent
{
    QMouseEvent *mouseevent;
    QKeyEvent   *keyevent;
    PaintCanvas *idcanvas;
    PaintCanvas *canvas;
    bool ispress=false;
    float w,h=0;
};
#endif // PAINTCANVAS_H
