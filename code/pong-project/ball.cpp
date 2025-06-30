#include "ball.h"
#include <QKeyEvent>
#include <QtMath>

// Ball::Ball(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
//     : QGraphicsEllipseItem(x,y,width,height,parent) {

//     dx = 0;
//     dy = 0;

// }

Ball::Ball(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : QGraphicsEllipseItem(x, y, width, height, parent) // Chama o construtor da classe base
{
    // Define a cor da bola
    QBrush ballBrush(Qt::white); // Bola branca
    setBrush(ballBrush);
}

// void Ball::setTarget(QPointF t)
// {
//     QPointF delta = t - pos();
//     float mag = qSqrt( (delta.x() * delta.x()) + (delta.y()*delta.y()) );
//     dx = delta.x()/mag;
//     dy = delta.y()/mag;

// }

void Ball::advance(int phase)
{
    if(!phase)
        return;

    moveBy(dx,dy);

}

void Ball::keyPressEvent(QKeyEvent *event)
{
    dx = 0;
    dy = 0;
    if( event->key() == Qt::Key_Left) {
        dx=-1;
    }
    if( event->key() == Qt::Key_Right) {
        dx=1;
    }
    if( event->key() == Qt::Key_Up) {
        dy=-1;
    }
    if( event->key() == Qt::Key_Down) {
        dy=1;
    }
}
