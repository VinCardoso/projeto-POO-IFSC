// paddle.cpp

#include "paddle.h"
#include <QDebug>

Paddle::Paddle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsRectItem(x, y, width, height, parent)
{
    setBrush(QBrush(Qt::darkGray));
}


void Paddle::moveUp()
{
    qDebug() << "[Up] Y:" << y() << "| ProposedY:" << y() - MOVE_SPEED;

    if (y() - MOVE_SPEED >= -110) {
        moveBy(0, - MOVE_SPEED);
    }
}


void Paddle::moveDown()
{

    qreal currentBottom = y() + rect().height();
    qreal proposedBottom = currentBottom + MOVE_SPEED;

    qDebug() << "[Down] Y:" << currentBottom << "| ProposedY:" << proposedBottom;

    if (proposedBottom < 260) {
        moveBy(0, MOVE_SPEED);
    }
}
