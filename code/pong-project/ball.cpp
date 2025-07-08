#include "ball.h"
#include "paddle.h" // Incluir para poder verificar o tipo
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>

#define SCENE_WIDTH 800
#define SCENE_HEIGHT 400
#define WALL_THICKNESS 20
#define GOAL_WIDTH 5

Ball::Ball(QGraphicsItem *parent)
    : QObject(), QGraphicsEllipseItem(parent)
{
    // Cria Bola
    setRect(0, 0, 20, 20);
    setBrush(Qt::white);

    // Velocidade inicial da bola
    _speedX = -2; // Começa se movendo para a esquerda
    _speedY = 0.5;  // Inicialmente não se move na vertical
}

void Ball::move()
{
    // Verificação de Colisão com Raquete
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (QGraphicsItem *item : colliding_items) {

        Paddle *paddle = dynamic_cast<Paddle*>(item);

        if (paddle) {
            // Colidiu com Raquete
            qDebug() << "Bateu na Raquete";
            _speedX = -_speedX * 1.1;
            qreal paddleCenter = paddle->y() + paddle->rect().height() / 2;
            qreal ballCenter = y() + rect().height() / 2;
            _speedY = (ballCenter - paddleCenter) / 100;
            setPos(x() + _speedX, y() + _speedY);
            return; // Sai da função após tratar a colisão com paddle
        }
    }

    // Bater nas paredes de cima e de baixo
    if (y() <= WALL_THICKNESS || y() + rect().height() >= SCENE_HEIGHT - WALL_THICKNESS) {
        qDebug() << "Bateu na Parede";
        _speedY = -_speedY;
    }


    // Bater no Gol no lado esquerdo
    if (x() <= GOAL_WIDTH) {
        qDebug() << "Gol do Jogador 2!";

        // Reposiciona a bola no centro
        setPos(SCENE_WIDTH / 2.0 - rect().width() / 2.0, SCENE_HEIGHT / 2.0 - rect().height() / 2.0);
        _speedX = 2;
        _speedY = 0.5;
        return;
    }

    // Bater no Gol no lado direito
    if (x() + rect().width() >= SCENE_WIDTH - GOAL_WIDTH) {
        qDebug() << "Gol do Jogador 1!";

        // Reposiciona a bola no centro
        setPos(SCENE_WIDTH / 2.0 - rect().width() / 2.0, SCENE_HEIGHT / 2.0 - rect().height() / 2.0);
        _speedX = 1;
        _speedY = 0.5;
        return;
    }

    // Move a bola com base na sua velocidade
    setPos(x() + _speedX, y() + _speedY);
}
