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
    ui->W_Editor->keyPressEvent(event);
}
void MainWindow::keyReleaseEvent    (QKeyEvent *event)
{
    ui->W_Editor->keyReleaseEvent(event);
}
