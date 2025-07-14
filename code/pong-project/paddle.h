#ifndef PADDLE_H
#define PADDLE_H

#include <QGraphicsRectItem>
#include <QBrush>

#include "game_object.h"
#include "constants.h"


class Paddle : public game_object{

    Q_OBJECT

private:
    int p_playerID;
    qreal p_minY;
    qreal p_maxY;
    bool p_isMovingUp;
    bool p_isMovingDown;

public:

    // Construtor da raquete.
    Paddle(int playerID, const QPointF& initialPosition);

    // Atualiza a posição da raquete.
    void update(qint64 deltaTime) override;

    // Desenha a raquete na tela.
    void draw(QPainter* painter) override;

    // Define os limites superior e inferior para o movimento da raquete.
    void setMovementBounds(qreal minY, qreal maxY);

    // Define se a raquete está se movendo para cima.
    void setMovingUp(bool moving);

    // Define se a raquete está se movendo para baixo.
    void setMovingDown(bool moving);

};

#endif // PADDLE_H
