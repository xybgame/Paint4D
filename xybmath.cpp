#include "xybmath.h"

//矩阵类实现
XYBMatrix4x4::XYBMatrix4x4()
{
    for(uint i=0;i<4;++i)
    {
        for(uint j=0;j<4;++j)
        {
            data[i][j]=0;
        }
    }
}
XYBMatrix4x4::XYBMatrix4x4(Xfloat m00, Xfloat m01, Xfloat m02, Xfloat m03,
                           Xfloat m10, Xfloat m11, Xfloat m12, Xfloat m13,
                           Xfloat m20, Xfloat m21, Xfloat m22, Xfloat m23,
                           Xfloat m30, Xfloat m31, Xfloat m32, Xfloat m33)
{
    data[0][0]=m00;data[0][1]=m01;data[0][2]=m02;data[0][3]=m03;
    data[1][0]=m10;data[1][1]=m11;data[1][2]=m12;data[1][3]=m13;
    data[2][0]=m20;data[2][1]=m21;data[2][2]=m22;data[2][3]=m23;
    data[3][0]=m30;data[3][1]=m31;data[3][2]=m32;data[3][3]=m33;
}

void XYBMatrix4x4::xyb_SetData          (Xfloat m00, Xfloat m01, Xfloat m02, Xfloat m03,
                                         Xfloat m10, Xfloat m11, Xfloat m12, Xfloat m13,
                                         Xfloat m20, Xfloat m21, Xfloat m22, Xfloat m23,
                                         Xfloat m30, Xfloat m31, Xfloat m32, Xfloat m33)
{
    data[0][0]=m00;data[0][1]=m01;data[0][2]=m02;data[0][3]=m03;
    data[1][0]=m10;data[1][1]=m11;data[1][2]=m12;data[1][3]=m13;
    data[2][0]=m20;data[2][1]=m21;data[2][2]=m22;data[2][3]=m23;
    data[3][0]=m30;data[3][1]=m31;data[3][2]=m32;data[3][3]=m33;
}
void XYBMatrix4x4::xyb_SetIdentity      ()
{
    xyb_SetData(1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1);
}
void XYBMatrix4x4::xyb_SetPerspective   (Xfloat aspect, Xfloat fovy, Xfloat n, Xfloat f)
{
    float a=qTan(fovy*0.5);
    float fmn=f-n;
    xyb_SetData(1/a,0,0,0,
                0,aspect/a,0,0,
                0,0,-1/fmn,-n/fmn,
                0,0,1,0);
}
void XYBMatrix4x4::xyb_SetTranslate     (Xfloat x, Xfloat y, Xfloat z)
{
    xyb_SetData(1,0,0,x,
                0,1,0,y,
                0,0,1,z,
                0,0,0,1);
}
void XYBMatrix4x4::xyb_SetScale         (Xfloat x, Xfloat y, Xfloat z)
{
    xyb_SetData(x,0,0,0,
                0,y,0,0,
                0,0,z,0,
                0,0,0,1);
}
void XYBMatrix4x4::xyb_SetRotX          (float angle)
{
    float s=qSin(angle);
    float c=qCos(angle);
    xyb_SetData(1,0,0,0,
                0,c,-s,0,
                0,s,c,0,
                0,0,0,1);
}
void XYBMatrix4x4::xyb_SetRotY          (float angle)
{
    float s=qSin(angle);
    float c=qCos(angle);
    xyb_SetData(c,0,s,0,
                0,1,0,0,
                -s,0,c,0,
                0,0,0,1);
}

XYBMatrix4x4    XYBMatrix4x4::operator *    (XYBMatrix4x4 m)
{
    XYBMatrix4x4 r;

    for (uint i=0;i<4;++i)
    {
        for (uint j=0;j<4;++j)
        {
            for (uint k=0;k<4;++k)
            {
                r.data[i][j]+=data[i][k]*m.data[k][j];
            }
        }
    }

    return r;
}

//向量类实现
XYBVec4::XYBVec4()
{
    for (uint i=0;i<4;++i)
    {
        data[i]=0;
    }
}
XYBVec4::XYBVec4(Xfloat x, Xfloat y, Xfloat z, Xfloat w)
{
    data[0]=x;data[1]=y;data[2]=z;data[3]=w;
}

void    XYBVec4::xyb_SetData        (Xfloat x, Xfloat y, Xfloat z, Xfloat w)
{
    data[0]=x;data[1]=y;data[2]=z;data[3]=w;
}
void    XYBVec4::xyb_Normalize      ()
{
    Xfloat norm=xyb_GetNorm();
    for (int i = 0; i < 4; ++i)
    {
        data[i]=data[i]/norm;
    }
}
Xfloat  XYBVec4::xyb_GetNorm        ()
{
    Xfloat r=0.0f;
    for (int i = 0; i < 4; ++i)
    {
        r+=(data[i]*data[i]);
    }
    r=qSqrt(r);
    return r;
}
XYBVec4 XYBVec4::xyb_GetNormalize   ()
{
    XYBVec4 r;
    Xfloat norm=xyb_GetNorm();
    for (int i = 0; i < 4; ++i)
    {
        r.data[i]=data[i]/norm;
    }
    return r;
}

XYBVec4 XYBVec4::operator * (XYBMatrix4x4 m)
{
    XYBVec4 r;
    for (int j = 0; j < 4; ++j)
    {
        for (int k = 0; k < 4; ++k)
        {
            r.data[j]+=data[j]*m.data[k][j];
        }
    }
    return r;
}
