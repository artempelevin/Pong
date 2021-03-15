#ifndef BALL_H
#define BALL_H

#include <QObject>

enum {X_ROTATE = -1,
      X_NOT_ROTATE = 1,
      Y_ROTATE  = -1,
      Y_NOT_ROTATE = 1
     };

class Ball: public QObject{
    Q_OBJECT;
private:
    int x, y;
    int dx, dy;
signals:
    void ballHasMoved();
public slots:
    void move();
    void move(const int& x, const int& y);
public:
    Ball(const int& x, const int& y, const int& dx, const int& dy, QObject *parent);
     ~Ball();
    const int& getX() const;
    const int& getY() const;
    void rotate(int x_sign, int y_sign);
};

#endif // BALL_H
