#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>

#include "game_object.h"
#include "constants.h"
#include <QVector2D> // Para vetor de 2D (velocidade)
#include <QRandomGenerator> // Para gerar direções aleatórias

class Ball : public game_object
{
    Q_OBJECT

public:
     Ball();

    // Atualiza a posição da bola com base na sua velocidade e no tempo decorrido.
    void update(qint64 deltaTime) override;

    // Desenha a bola na tela.
    void draw(QPainter* painter) override;

    // Reinicia a bola para a posição central e define uma nova direção aleatória.
    void reset();

    // Inverte a direção horizontal da bola (rebatida em raquete).
    void deflectX();

    // Inverte a direção vertical da bola (rebatida em parede).
    void deflectY();

    // Aumenta a velocidade da bola.
    void increaseSpeed();

    // Retorna a velocidade atual da bola.
    QVector2D getVelocity() const;

    void setVelocity(const QVector2D& velocity);

private:
    QVector2D m_velocity; // Vetor de velocidade (direção e magnitude)
    qreal m_currentSpeed; // Velocidade atual da bola
};

#endif // BALL_H
