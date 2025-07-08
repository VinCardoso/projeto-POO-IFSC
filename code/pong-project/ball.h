#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject> // Necessário para usar QTimer e outros recursos do Qt

class Ball : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT // Macro necessária para classes com signals e slots

public:
    Ball(QGraphicsItem *parent = nullptr);

    qreal speedX() const;
    qreal speedY() const;

    void setSpeedX(qreal newSpeedX);
    void setSpeedY(qreal newSpeedY);

public slots:
    void move(); // Slot que será chamado pelo timer para mover a bola

private:
    qreal _speedX;
    qreal _speedY;
};

#endif // BALL_H
