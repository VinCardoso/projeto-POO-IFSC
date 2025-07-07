#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include "paddle.h"

class MyScene : public QGraphicsScene
{
    Paddle * _player1Paddle;
    Paddle * _player2Paddle;

public:
    explicit MyScene(QObject *parent = nullptr);

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYSCENE_H
