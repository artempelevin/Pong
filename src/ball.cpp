#include <algorithm>
#include "ball.h"

Ball::Ball(const int& x, const int& y, const int& dx, const int& dy, QObject *parent=nullptr)
    :QObject(parent), x(x), y(y), dx(dx), dy(dy)    {}

Ball::~Ball() {}

const int& Ball::getX() const   {return x;}
const int& Ball::getY() const   {return y;}


void Ball::move(){
    x += dx;
    y += dy;
    ballHasMoved();
}

void Ball::move(const int& x, const int& y){
    this->x = x;
    this->y = y;
    ballHasMoved();
}
void Ball::rotate(int x_sign, int y_sign){
    std::swap(dx, dy);
    dx *= x_sign;
    dy *= y_sign;
}

