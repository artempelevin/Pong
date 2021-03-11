#ifndef BALL_H
#define BALL_H

class Ball{
private:
    int x, y;
    int dx, dy;
public:
    Ball(const int& x, const int& y, const int& dx, const int& dy);

    const int& getX() const;
    const int& getY() const;
    void rotate(int x_sign, int y_sign);
    void move();
    void move(const int& x, const int& y);
};

#endif // BALL_H
