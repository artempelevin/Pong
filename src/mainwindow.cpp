#include "mainwindow.h"
#include <QDebug>
#include <QTimer>

#include "ui_mainwindow.h"
#include "setting.h"

// ЗАРЕФАЧИТЬ ВСЮ РЕАЛИЗАЦИЮ, А ТО ТУТ ЧЁРТ НОГУ СЛОМИТ ЧТО НАПИСАНО

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->start(UPDATE_RATE);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveBall()));

    ball = new Ball(ui->ball->x(), ui->ball->y(), -BALL_SPEED, -BALL_SPEED);
    ui->racket1->setStyleSheet("background-color: rgb(45, 196, 136);");
    ui->ball->setStyleSheet("background-color: rgb(45, 138, 196);");

    ui->ball->setFocus();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    int mouseY = mapFromGlobal(QCursor::pos()).y();
    int racketX = ui->racket1->x();
    int racketY = ui->racket1->y();
    int racketHeight = ui->racket1->height();

    if(mouseY - racketHeight/2 >= 0 && mouseY + racketHeight/2 <= SCREEN_HEIGHT){
        ui->racket1->move(racketX, mouseY - racketHeight/2);
    }
    else if(mouseY - racketHeight/2 < 0){
        ui->racket1->move(0, 0);
    }
    else if(mouseY + racketHeight/2 > SCREEN_HEIGHT){
        ui->racket1->move(0,  SCREEN_HEIGHT - racketHeight);
    }
}


void MainWindow::moveBall(){
    int ballX = ball->getX();
    int ballY = ball->getY();
    int ballSize = ui->ball->height();

    int racketX = ui->racket1->x();
    int racketY = ui->racket1->y();
    int racketWidth  = ui->racket1->width();
    int racketHeight = ui->racket1->height();

    if(ballX <= racketX + racketWidth){     // Столкновение с левой стеной
        if(ballY >= racketY && ballY <= racketY + racketHeight){
            ball->rotate(X_ROTATE, Y_NOT_ROTATE);
        }
        else {
            ball->move(SCREEN_CENTRE_X, SCREEN_CENTRE_Y);
        }
    }
    else if(ballX >= SCREEN_WIDTH - ballSize){  // Столкновение с правой стеной
        ball->rotate(X_ROTATE, Y_NOT_ROTATE);
    }
    else if(ballX <= 0){    // Столкновение с потолком
        ball->rotate(X_NOT_ROTATE, Y_ROTATE);
    }
    else if(ballY >= SCREEN_HEIGHT - ballSize){  // Столкновение с полом
        ball->rotate(X_NOT_ROTATE, Y_ROTATE);
    }

//ШАР УЛЕТАЕТ ПОЧЕМУ ТО В БОК ЭКРАНА, ИСПРАВЬ ЭТО НЕДОРОЗУМЕНИяе
    ball->move();
    ui->ball->move(ball->getX(), ball->getY());

}

MainWindow::~MainWindow()
{
    delete ui;
}

