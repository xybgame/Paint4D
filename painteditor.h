#ifndef PAINTEDITOR_H
#define PAINTEDITOR_H

#include "Component/componentcanvascontrol.h"
#include "Component/componentcanvas.h"

class PaintEditor : public QOpenGLWidget,XYBOPENGL
{
    Q_OBJECT
private:
    PaintCanvas idcanvas,       //用来储存三角形id索引信息方便拾取
                canvas;         //绘制编辑器的画布显示
public:
    XYBEvent e;
    QVector <Component*> com;   //事件组件列表
    explicit PaintEditor(QWidget *parent = nullptr);
protected:
    void initializeGL   ();
    void resizeGL       (int w, int h);
    void paintGL        ();
protected:
    void mousePressEvent        (QMouseEvent *event);
    void mouseReleaseEvent      (QMouseEvent *event);
    void mouseMoveEvent         (QMouseEvent *event);
public:
    void keyPressEvent  (QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

};

#endif // PAINTEDITOR_H
