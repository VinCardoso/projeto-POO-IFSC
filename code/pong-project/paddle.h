#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QBrush>

class Paddle : public QGraphicsRectItem
{
private:
    static const int MOVE_SPEED = 20;

public:
    Paddle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    void moveUp();
    void moveDown();
};

#endif // PADDLE_H
