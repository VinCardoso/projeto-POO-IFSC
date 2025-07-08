#include "paddle.h"
#include <QDebug>

Paddle::Paddle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    setBrush(QBrush(Qt::darkGray));
}


void Paddle::moveUp()
{
    if (y() - MOVE_SPEED >= -110) {
        moveBy(0, - MOVE_SPEED);
    }
}


void Paddle::moveDown()
{

    qreal currentBottom = y() + rect().height();
    qreal proposedBottom = currentBottom + MOVE_SPEED;

    if (proposedBottom < 260) {
        moveBy(0, MOVE_SPEED);
    }
}
