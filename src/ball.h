#ifndef BALL_H
#define BALL_H

enum {X_ROTATE = -1,
      X_NOT_ROTATE = 1,
      Y_ROTATE  = -1,
      Y_NOT_ROTATE = 1
     };

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
