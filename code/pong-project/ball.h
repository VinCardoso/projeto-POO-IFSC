#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>

class Ball : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    Ball(QGraphicsItem *parent = nullptr);

public slots:
    void move();

private:
    qreal _speedX;
    qreal _speedY;
};

#endif // BALL_H
