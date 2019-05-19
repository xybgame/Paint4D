#ifndef XYBMODEL_H
#define XYBMODEL_H

#include <QFile>

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#include "xybmath.h"

struct XYBVertex
{
    float data[10];
};
struct XYBTriangle
{
    float data[30];
};

class XYBMaterial
{
private:
    QString xyb_LoadFileString(QString path)
    {
        QFile file(path);
        file.open(QFile::ReadWrite);
        QByteArray b=file.readAll();
        QString s(b);
        file.close();
        return s;
    }
public:
    QString vs,fs;
public:
    void xyb_LoadMaterialFromFile(QString vspath,QString fspath)
    {
        vs=xyb_LoadFileString(vspath);
        fs=xyb_LoadFileString(fspath);
    }
};
class XYBModel
{
public:
    float *data;
    uint  *index;
    uint  mNumVertex,mNumIndex;
public:
    void xyb_LoadModelFromFile(QString path);
};

#endif // XYBMODEL_H
