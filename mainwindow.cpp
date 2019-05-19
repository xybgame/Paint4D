#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    XYBMatrix4x4 m( 1,0,0,0,
                    0,5,0,0,
                    0,0,1,0,
                    0,0,0,1);
    XYBVec4 v(1,2,3,4);

    XYBVec4 c=v*m;
}

MainWindow::~MainWindow()
{
    delete ui;
}
