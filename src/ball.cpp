#include <algorithm>
#include "ball.h"

Ball::Ball(const int& x, const int& y, const int& dx, const int& dy)
    : x(x), y(y), dx(dx), dy(dy){}

const int& Ball::getX() const   {return x;}
const int& Ball::getY() const   {return y;}

void Ball::move(){
    x += dx;
    y += dy;
}

void Ball::move(const int& x, const int& y){
    this->x = x;
    this->y = y;
}
void Ball::rotate(int x_sign, int y_sign){
    std::swap(dx, dy);
    dx *= x_sign;
    dy *= y_sign;
}

