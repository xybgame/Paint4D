#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent      (QKeyEvent *event)
{
    //event赋值
    ui->W_Editor->e.keyevent=event;
    /*执行Component*/
    {
        uint i=0;
        uint length=ui->W_Editor->com.length();
        for (; i < length; ++i)
        {
            ui->W_Editor->com.value(i)->xyb_KeyPress(ui->W_Editor->e);
        }
    }
    ui->W_Editor->update();
}
void MainWindow::keyReleaseEvent    (QKeyEvent *event)
{
    //event赋值
     ui->W_Editor->e.keyevent=event;
     /*执行Component*/
     {
         uint i=0;
         uint length=ui->W_Editor->com.length();
         for (; i < length; ++i)
         {
             ui->W_Editor->com.value(i)->xyb_KeyRelease(ui->W_Editor->e);
         }
     }
     ui->W_Editor->update();
}
