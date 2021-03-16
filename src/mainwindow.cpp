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

    scene = new Scene();
    scene->createBall(BALL_START_X, BALL_START_Y, -BALL_SPEED, -BALL_SPEED);
    scene->createRacket(0, SCREEN_CENTRE_Y - RACKET_HEIGHT/2, RACKET_WIDTH, RACKET_HEIGHT, 1);
    scene->createRacket(SCREEN_WIDTH - RACKET_WIDTH, SCREEN_CENTRE_Y  - RACKET_HEIGHT/2, RACKET_WIDTH, RACKET_HEIGHT, 2);

    ui->racket1->setStyleSheet("background-color: rgb(45, 196, 136);");
    ui->racket2->setStyleSheet("background-color: rgb(170, 40, 30);");
    ui->ball->setStyleSheet("background-color: rgb(45, 138, 196);");

    ui->racket1->setGeometry(scene->racket1->getX(), scene->racket1->getY(), scene->racket1->getW(), scene->racket1->getH());
    ui->racket2->setGeometry(scene->racket2->getX(), scene->racket2->getY(), scene->racket2->getW(), scene->racket2->getH());
    ui->ball->setGeometry(scene->ball->getX(), scene->ball->getY(), BALL_SIZE, BALL_SIZE);

    connect(scene->ball,    SIGNAL(ballHasMoved()),   this, SLOT(drawingBall()));
    connect(scene->racket1, SIGNAL(racketHasMoved()), this, SLOT(drawingRacket()));
    connect(scene->racket2, SIGNAL(racketHasMoved()), this, SLOT(drawingRacket()));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    int mouseY = mapFromGlobal(QCursor::pos()).y();

    if(mouseY - RACKET_HEIGHT/2 >= 0 && mouseY + RACKET_HEIGHT/2 <= SCREEN_HEIGHT){
        scene->racket1->setY(mouseY - RACKET_HEIGHT/2);
    }
    else if(mouseY - RACKET_HEIGHT/2 < 0){
        scene->racket1->setY(0);
    }
    else if(mouseY + RACKET_HEIGHT/2 > SCREEN_HEIGHT){
        scene->racket1->setY(SCREEN_HEIGHT - RACKET_HEIGHT);
    }
}


void MainWindow::drawingBall(){

    ui->ball->move(scene->ball->getX(), scene->ball->getY());

}

void MainWindow::drawingRacket(){
    Racket* racket = static_cast<Racket*>(QObject::sender());

    if(racket->getIndex() == 1){
        ui->racket1->move(racket->getX(), racket->getY());
    }
    if(racket->getIndex() == 2){
        ui->racket2->move(racket->getX(), racket->getY());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

