#include "paddle.h"

Paddle::Paddle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    QBrush paddleBrush(Qt::darkGray);
    setBrush(paddleBrush);
}
