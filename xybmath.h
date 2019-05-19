#ifndef XYBMATH_H
#define XYBMATH_H

#include <QtMath>
#include <QDebug>

#define Xfloat float

//矩阵类4x4
class XYBMatrix4x4
{
public:
    Xfloat data[4][4];
public:
    XYBMatrix4x4();
    XYBMatrix4x4(Xfloat m00,Xfloat m01,Xfloat m02,Xfloat m03,
                 Xfloat m10,Xfloat m11,Xfloat m12,Xfloat m13,
                 Xfloat m20,Xfloat m21,Xfloat m22,Xfloat m23,
                 Xfloat m30,Xfloat m31,Xfloat m32,Xfloat m33);
public:
    void xyb_SetData        (Xfloat m00,Xfloat m01,Xfloat m02,Xfloat m03,
                             Xfloat m10,Xfloat m11,Xfloat m12,Xfloat m13,
                             Xfloat m20,Xfloat m21,Xfloat m22,Xfloat m23,
                             Xfloat m30,Xfloat m31,Xfloat m32,Xfloat m33);
    void xyb_SetIdentity    ();
    void xyb_SetPerspective (Xfloat aspect,Xfloat fovy,Xfloat n,Xfloat f);
    void xyb_SetTranslate   (Xfloat x,Xfloat y,Xfloat z);
    void xyb_SetScale       (Xfloat x,Xfloat y,Xfloat z);
    void xyb_SetRotX        (Xfloat angle);
    void xyb_SetRotY        (Xfloat angle);
public:
    XYBMatrix4x4    operator *  (XYBMatrix4x4 m);
};

//向量类4
class XYBVec4
{
public:
    Xfloat data[4];
public:
    XYBVec4();
    XYBVec4(Xfloat x,Xfloat y,Xfloat z,Xfloat w);
public:
    void    xyb_SetData         (Xfloat x,Xfloat y,Xfloat z,Xfloat w);          //数据赋值初始化
    void    xyb_Normalize       ();                                             //归一化
    Xfloat  xyb_GetNorm         ();                                             //求向量模
    XYBVec4 xyb_GetNormalize    ();                                             //获得归一化向量
public:
    XYBVec4         operator *  (XYBMatrix4x4 m);
};

#endif // XYBMATH_H
