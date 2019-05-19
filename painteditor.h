#ifndef PAINTEDITOR_H
#define PAINTEDITOR_H

#include <QMouseEvent>
#include "paintcanvas.h"

struct XYBEvent
{
    int x,y=0;
    bool ispress=false;
};

class PaintEditor : public QOpenGLWidget,XYBOPENGL
{
    Q_OBJECT
private:
    XYBEvent e;
    PaintCanvas canvas;
public:
    explicit PaintEditor(QWidget *parent = nullptr);
protected:
    void initializeGL   ();
    void resizeGL       (int w, int h);
    void paintGL        ();
protected:
    void mousePressEvent        (QMouseEvent *event);
    void mouseReleaseEvent      (QMouseEvent *event);
    void mouseMoveEvent         (QMouseEvent *event);

};

#endif // PAINTEDITOR_H
