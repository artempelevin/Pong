#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QTimer>

#include "ball.h"
#include "racket.h"

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    void createBall(const int x, const int y, const int dx, const int dy);
    void createRacket(const int x, const int y, const int w, const int h, const int index);
public slots:
    void ballPhysicsProcessing();
    void smartBot();
public:
    Ball* ball;
    Racket* racket1;
    Racket* racket2;
private:
    QTimer *timer;
};


#endif // SCENE_H
