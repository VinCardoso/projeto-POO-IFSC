#include "ball.h"
#include <cmath>

// Construtor da bola.
Ball::Ball()
    : game_object(QPointF((Constants::SCENE_WIDTH - Constants::BALL_SIZE.width()) / 2,
                         (Constants::SCENE_HEIGHT - Constants::BALL_SIZE.height()) / 2),
                 Constants::BALL_SIZE) {
    reset(); // Inicializa a bola na posição central com velocidade aleatória.
}

// Atualiza a posição da bola.
void Ball::update(qint64 deltaTime) {
    // Calcula o deslocamento com base na velocidade e no tempo decorrido.
    qreal deltaSeconds = static_cast<qreal>(deltaTime) / 1000.0;
    o_position += m_velocity.toPointF() * deltaSeconds;
}

// Desenha a bola como um círculo.
void Ball::draw(QPainter* painter) {
    painter->setBrush(Qt::white); // Cor da bola
    painter->setPen(Qt::NoPen);   // Sem borda
    painter->drawEllipse(getRect()); // Desenha um círculo dentro do retângulo da bola
}

// Reinicia a bola para o centro da tela com uma direção aleatória.
void Ball::reset() {
    o_position = QPointF((Constants::SCENE_WIDTH - Constants::BALL_SIZE.width()) / 2,
                         (Constants::SCENE_HEIGHT - Constants::BALL_SIZE.height()) / 2);
    m_currentSpeed = Constants::BALL_INITIAL_SPEED;

    // Gera um ângulo aleatório para a direção inicial da bola.
    qreal angle;
    do {
        angle = QRandomGenerator::global()->generateDouble() * (2.0 * M_PI);
    } while (qAbs(qCos(angle)) < 0.2 || qAbs(qSin(angle)) < 0.2);

    // Define a velocidade inicial com base no ângulo.
    m_velocity = QVector2D(m_currentSpeed * qCos(angle), m_currentSpeed * qSin(angle));
}

// Inverte a componente X da velocidade da bola.
void Ball::deflectX() {
    m_velocity.setX(-m_velocity.x());
}

// Inverte a componente Y da velocidade da bola.
void Ball::deflectY() {
    m_velocity.setY(-m_velocity.y());
}

// Aumenta a velocidade da bola.
void Ball::increaseSpeed() {
    m_currentSpeed *= Constants::BALL_SPEED_INCREASE_FACTOR;
    m_velocity = m_velocity.normalized() * m_currentSpeed; // Mantém a direção, mas aumenta a magnitude
}

// Retorna a velocidade atual da bola.
QVector2D Ball::getVelocity() const {
    return m_velocity;
}
