#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ball.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    virtual void mouseMoveEvent(QMouseEvent *event);
private slots:
    void moveBall();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Ball *ball;
};
#endif // MAINWINDOW_H
