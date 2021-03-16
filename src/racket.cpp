#include "racket.h"
#include "setting.h"

Racket::Racket(const int x, const int y, const int w, const int h, const int index, QObject *parent)
    : QObject(parent), x(x), y(y), w(w), h(h), index(index){}

const int& Racket::getX() const {return x;}
const int& Racket::getY() const {return y;}
const int& Racket::getW() const {return w;}
const int& Racket::getH() const {return h;}
const int& Racket::getIndex() const {return index;}

void Racket::setX(const int x)  {this->x = x;}
void Racket::setY(const int y)  {
    this->y = y;
    emit racketHasMoved();
}

void Racket::moveUp(){
    if(y <= 0){
        y -= RACKET_SPEED;
        emit racketHasMoved();
    }
}
void Racket::moveDown(){
    if(y <= SCREEN_WIDTH){
        y += RACKET_SPEED;
        emit racketHasMoved();
    }
}
