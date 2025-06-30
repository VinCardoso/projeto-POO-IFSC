#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QBrush>

class Paddle : public QGraphicsRectItem
{
public:
    Paddle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);
};

#endif // PADDLE_H
