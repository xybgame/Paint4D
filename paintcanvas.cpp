#include "paintcanvas.h"

void PaintCanvas::xyb_Create(QString path, QString vspath, QString fspath)
{
    initializeOpenGLFunctions();
    //初始化基本矩阵
    {
        pers    .xyb_SetPerspective (1,45,10,1000);
        trans   .xyb_SetTranslate   (0,0,0);
        scale   .xyb_SetScale       (1,1,1);
        rotx    .xyb_SetRotX        (0);
        roty    .xyb_SetRotY        (0);
    }
    //读取着色器代码，读取模型基本数据源信息
    {
        material.xyb_LoadMaterialFromFile(vspath,fspath);
        model.xyb_LoadModelFromFile(path);
    }

    //整合信息：模型数据结构重组成方便操控的Triangle类的集合
    {
        trianglelist=new XYBTriangle[model.mNumIndex/3];
        for (uint i = 0; i < model.mNumIndex; i+=3)
        {
            uint index0=model.index[i+0]*10;
            uint index1=model.index[i+1]*10;
            uint index2=model.index[i+2]*10;

            for (uint j = 0; j < 10; ++j)
            {
                trianglelist[i/3].data[j]=model.data[index0+j];
            }
            for (uint j = 10; j < 20; ++j)
            {
                trianglelist[i/3].data[j]=model.data[index1+j-10];
            }
            for (uint j = 20; j < 30; ++j)
            {
                trianglelist[i/3].data[j]=model.data[index2+j-20];
            }
        }
    }
}

void PaintCanvas::xyb_UpdateGL  (GLenum drawtype)
{
    glUseProgram(program);
    glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);

    glUniformMatrix4fv(mpers,   1,false,&pers   .data[0][0]);
    glUniformMatrix4fv(mtrans,  1,false,&trans  .data[0][0]);
    glUniformMatrix4fv(mrotx,   1,false,&rotx   .data[0][0]);
    glUniformMatrix4fv(mroty,   1,false,&roty   .data[0][0]);
    glUniformMatrix4fv(mscale,  1,false,&scale  .data[0][0]);

    glEnableVertexAttribArray(pos);
    glEnableVertexAttribArray(nor);
    glEnableVertexAttribArray(uv);

    glVertexAttribPointer(pos,  4,GL_FLOAT,false,40,(void*)0    );
    glVertexAttribPointer(nor,  3,GL_FLOAT,false,40,(void*)16   );
    glVertexAttribPointer(uv,   3,GL_FLOAT,false,40,(void*)28   );

    glDrawArrays(drawtype,0,model.mNumVertex*0.1);
}
void PaintCanvas::xyb_ResizeGL  (float w, float h)
{
    pers.xyb_SetPerspective(w/h,45,1,10000);
}
void PaintCanvas::xyb_InitGL    ()
{
    GLuint vsobj,fsobj;
    //vs
    {
        QByteArray b=material.vs.toLatin1();
        char *s=b.data();
        vsobj=glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vsobj,1,&s,NULL);
        glCompileShader(vsobj);
    }
    //fs
    {
        QByteArray b=material.fs.toLatin1();
        char *s=b.data();
        fsobj=glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fsobj,1,&s,NULL);
        glCompileShader(fsobj);
    }
    program=glCreateProgram();
    glAttachShader(program,vsobj);
    glAttachShader(program,fsobj);
    glLinkProgram(program);

    GLint isok;
    glGetProgramiv(program,GL_LINK_STATUS,&isok);
    if(!isok)
    {
        char log[1024];
        glGetProgramInfoLog(program,1024,NULL,log);
        qDebug()<<log;
    }

    glUseProgram(program);

    pos =glGetAttribLocation(program,"pos"  );
    nor =glGetAttribLocation(program,"nor"  );
    uv  =glGetAttribLocation(program,"uv"   );

    mtrans  =glGetUniformLocation(program,"trans"   );
    mpers   =glGetUniformLocation(program,"pers"    );
    mscale  =glGetUniformLocation(program,"scale"   );
    mrotx   =glGetUniformLocation(program,"rotx"    );
    mroty   =glGetUniformLocation(program,"roty"    );

    //vertex buffer
    {
        glGenBuffers(1,&vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER,vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER,model.mNumVertex*4,&trianglelist[0],GL_STATIC_DRAW);
    }
}
