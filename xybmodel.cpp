#include "xybmodel.h"

void XYBModel::xyb_LoadModelFromFile(QString path)
{
    QByteArray b=path.toLatin1();
    char*p=b.data();

    Assimp::Importer importer;
    const aiScene *scene=importer.ReadFile(p,aiProcess_Triangulate|aiProcess_GenNormals|aiProcess_FlipUVs);

    aiMesh *mesh=scene->mMeshes[0];

    //pos4 nor3 uv3    10
    mNumVertex=mesh->mNumVertices*10;
    mNumIndex=mesh->mNumFaces*3;
    data=new float[mNumVertex];
    index=new uint[mNumIndex];

    for (uint i = 0; i < mesh->mNumVertices; ++i)
    {
        uint pos=i*10;
        data[pos+0]=mesh->mVertices[i].x;
        data[pos+1]=mesh->mVertices[i].y;
        data[pos+2]=mesh->mVertices[i].z;
        data[pos+3]=1;

        data[pos+4]=mesh->mNormals[i].x;
        data[pos+5]=mesh->mNormals[i].y;
        data[pos+6]=mesh->mNormals[i].z;

        data[pos+7]=mesh->mTextureCoords[0][i].x;
        data[pos+8]=mesh->mTextureCoords[0][i].y;
        data[pos+9]=mesh->mTextureCoords[0][i].z;
    }

    for (uint i = 0; i < mesh->mNumFaces; ++i)
    {
        for (uint j = 0; j < 3; ++j)
        {
            index[i*3+j]=mesh->mFaces[i].mIndices[j];
        }
    }

}
