#include "paddle.h"


// Construtor da raquete.
Paddle::Paddle(int playerID, const QPointF& initialPosition)
    : game_object(initialPosition, Constants::PADDLE_SIZE),
    p_playerID(playerID),
    p_minY(0),
    p_maxY(Constants::SCENE_HEIGHT - Constants::PADDLE_SIZE.height()),
    p_isMovingUp(false),
    p_isMovingDown(false) {
}


// Atualiza a posição da raquete com base nos flags de movimento.
void Paddle::update(qint64 deltaTime) {
    qreal deltaSeconds = static_cast<qreal>(deltaTime) / 1000.0;
    qreal movementAmount = Constants::PADDLE_SPEED * deltaSeconds;

    if (p_isMovingUp) {
        // Garante que a raquete não ultrapasse o limite superior (p_minY)
        o_position.setY(std::max(p_minY, o_position.y() - movementAmount));
    }
    if (p_isMovingDown) {
        // Garante que a raquete não ultrapasse o limite inferior (p_maxY)
        o_position.setY(std::min(p_maxY, o_position.y() + movementAmount));
    }
}

// Desenha a raquete
void Paddle::draw(QPainter* painter) {
    painter->setBrush(Qt::gray); // Cor da raquete
    painter->setPen(Qt::NoPen);   // Sem borda
    painter->drawRect(getRect()); // Desenha a raquete
}

// Define os limites de movimento
void Paddle::setMovementBounds(qreal minY, qreal maxY) {
    p_minY = minY;
    p_maxY = maxY - o_size.height();
}

// Define o flag de movimento para cima.
void Paddle::setMovingUp(bool moving) {
    p_isMovingUp = moving;
}

// Define o flag de movimento para baixo.
void Paddle::setMovingDown(bool moving) {
    p_isMovingDown = moving;
}
