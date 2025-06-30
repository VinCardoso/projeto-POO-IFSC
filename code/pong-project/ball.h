#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QBrush>

class Ball : public QGraphicsEllipseItem
{
    qreal dx;
    qreal dy;

public:
    Ball(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = nullptr);

    // void setTarget(QPointF t);

    // QGraphicsItem interface
public:
    void advance(int phase) override;

    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // BALL_H
