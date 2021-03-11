#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    ui->racket1->setMouseTracking(true);

    timer = new QTimer(this);
    timer->start(3);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveBall()));

    ball = new Ball(ui->ball->x(), ui->ball->y(), -2, -2);

    ui->ball->setFocus();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    int mouseY = mapFromGlobal(QCursor::pos()).y();
    if(mouseY - ui->racket1->height()/2 >= 0 && mouseY + ui->racket1->height()/2 <= ui->centralwidget->height()){
        ui->racket1->move(ui->racket1->x(), mouseY - ui->racket1->height()/2);
    }
    else if(mouseY - ui->racket1->height()/2 < 0){
        ui->racket1->move(0, 0);
    }
    else if(mouseY + ui->racket1->height()/2 > ui->centralwidget->height()){
        ui->racket1->move(0,  ui->centralwidget->height() - ui->racket1->height());
    }
}


void MainWindow::moveBall(){
    if(ball->getX() <= ui->racket1->x() + ui->racket1->width()){    // Столкновение с левой стеной
        if(ball->getY() >= ui->racket1->y () && ball->getY() <= ui->racket1->y() + ui->racket1->height()){
            ball->rotate(-1, 1);
        }
        else{
            ball->move(200, 200);
        }
    }
    else if(ball->getX() >= ui->centralwidget->width()){        // Столкновение с правой стеной
        ball->rotate(-1, 1);
    }


    else if(ball->getY() <= 0){          // Столкновение с потолком
        ball->rotate(1, -1);
    }
    else if(ball->getY() >= ui->centralwidget->height()){       // Столкновение с полом
        ball->rotate(1, -1);
    }

//ШАР УЛЕТАЕТ ПОЧЕМУ ТО В БОК ЭКРАНА, ИСПРАВЬ ЭТО НЕДОРОЗУМЕНИяе
    ball->move();
    ui->ball->move(ball->getX(), ball->getY());

}

MainWindow::~MainWindow()
{
    delete ui;
}

