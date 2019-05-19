#ifndef PAINTCANVAS_H
#define PAINTCANVAS_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_4_Core>

#include "xybmodel.h"
#include "xybmath.h"

#define XYBOPENGL public QOpenGLFunctions_4_4_Core

class PaintCanvas:XYBOPENGL
{
private:
    XYBMaterial material;
    XYBModel    model;
    GLuint      program,vertexbuffer;
    GLuint      pos,nor,uv;
    GLuint      mtrans,mpers,mrotx,mroty,mscale;
public:
    XYBMatrix4x4 pers,trans,rotx,roty,scale;

    XYBTriangle *trianglelist;
public:
    void xyb_Create(QString path, QString vspath, QString fspath);
    void xyb_InitGL();
    void xyb_UpdateGL(GLenum drawtype);
    void xyb_ResizeGL(float w,float h);
};

#endif // PAINTCANVAS_H
