#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
// #include <QTimer>
// #include "ball.h"
#include "paddle.h"

class MyScene : public QGraphicsScene
{
    // QGraphicsRectItem * _rect;
    // Ball * _ball;
    // QTimer * _timer;
    Paddle * _player1Paddle;
    Paddle * _player2Paddle;

public:
    explicit MyScene(QObject *parent = nullptr);

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;

    // QGraphicsScene interface
// protected:
    // void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    // void setupBall();
    // void setupPaddles();

    // Ball *gameBall;
    // Paddle *player1Paddle;
};

#endif // MYSCENE_H
