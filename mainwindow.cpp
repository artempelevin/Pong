#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QCursor>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    ui->pushButton->setMouseTracking(true);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    int mouseY = mapFromGlobal(QCursor::pos()).y();
    if(mouseY - ui->pushButton->height()/2 >= 0 && mouseY + ui->pushButton->height()/2 <= ui->centralwidget->height()){
        ui->pushButton->move(ui->pushButton->x(), mouseY - ui->pushButton->height()/2);
    }
    else if(mouseY - ui->pushButton->height()/2 < 0){
        ui->pushButton->move(0, 0);
    }
    else if(mouseY + ui->pushButton->height()/2 > ui->centralwidget->height()){
        ui->pushButton->move(0,  ui->centralwidget->height() - ui->pushButton->height());
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

