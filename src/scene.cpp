#include "scene.h"
#include "setting.h"

Scene::Scene(QObject *parent) : QObject(parent) {
    timer = new QTimer(this);
    timer->start(UPDATE_RATE);
}

void Scene::createBall(const int x, const int y, const int dx, const int dy){
    ball = new Ball(x, y, dx, dy);
    connect(timer, SIGNAL(timeout()), ball, SLOT(move()));
    connect(ball, SIGNAL(ballHasMoved()), this, SLOT(ballPhysicsProcessing()));
}

void Scene::createRacket(const int x, const int y, const int w, const int h, const int index){
    if(index == 1)  racket1 = new Racket(x, y, w, h, index);
    if(index == 2)  racket2 = new Racket(x, y, w, h, index);
    connect(timer, SIGNAL(timeout()), this, SLOT(smartBot()));
}


void Scene::ballPhysicsProcessing(){
    int ballX = ball->getX();
    int ballY = ball->getY();

    int racket1X = racket1->getX();
    int racket1Y = racket1->getY();
    int racket2Y = racket2->getY();

    if(ballX < racket1X + RACKET_WIDTH){     // Столкновение с левой стеной
        if(ballY >= racket1Y && ballY <= racket1Y + RACKET_HEIGHT){
            ball->rotate(X_ROTATE, Y_NOT_ROTATE);
        }
        else {
            ball->move(SCREEN_CENTRE_X, SCREEN_CENTRE_Y);
        }
    }
    else if(ballX > SCREEN_WIDTH - BALL_SIZE - RACKET_WIDTH){  // Столкновение с правой стеной
        if(ballY >= racket2Y && ballY <= racket2Y + RACKET_HEIGHT){
            ball->rotate(X_ROTATE, Y_NOT_ROTATE);
        }
        else {
            ball->move(SCREEN_CENTRE_X, SCREEN_CENTRE_Y);
        }
    }
    else if(ballY <= 0){    // Столкновение с потолком
        ball->rotate(X_NOT_ROTATE, Y_ROTATE);
    }
    else if(ballY >= SCREEN_HEIGHT - BALL_SIZE){  // Столкновение с полом
        ball->rotate(X_NOT_ROTATE, Y_ROTATE);
    }
}

void Scene::smartBot(){
    int ballY = ball->getY();
    if(ballY - RACKET_HEIGHT/2 >= 0 && ballY + RACKET_HEIGHT/2 <= SCREEN_HEIGHT){
        racket2->setY(ball->getY() - RACKET_HEIGHT/2);
    }
    else if(ballY - RACKET_HEIGHT/2 < 0){
        racket2->setY(0);
    }
    else if(ballY + RACKET_HEIGHT/2 > SCREEN_HEIGHT){
        racket2->setY(SCREEN_HEIGHT - RACKET_HEIGHT);
    }
}
