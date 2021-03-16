#ifndef RACKET_H
#define RACKET_H

#include <QObject>

class Racket : public QObject
{
    Q_OBJECT
private:
    int x, y;
    int w, h;
    int index;
public:
    explicit Racket(const int x, const int y, const int w, const int h, const int index, QObject *parent = nullptr);
    const int& getX() const;
    const int& getY() const;
    const int& getW() const;
    const int& getH() const;
    const int& getIndex() const;
    void setX(const int x);
    void setY(const int y);

public slots:
    void moveUp();
    void moveDown();
signals:
    void racketHasMoved();
};

#endif // RACKET_H
