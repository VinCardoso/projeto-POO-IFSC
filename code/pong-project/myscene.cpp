#include "myscene.h"
#include <QDebug>
#include <QPointF>

// Variáveis
#define SCENE_WIDTH 800
#define SCENE_HEIGHT 400
#define WALL_THICKNESS 20

#define BALL_SIZE 20

#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_MARGIN 10

#define PADDLE_MOVE_SPEED 1


MyScene::MyScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(Qt::black); // Cor do fundo
    QBrush wallBrush(Qt::darkGray); // Cor dos itens;

    // Parede de Cima
    QGraphicsRectItem *topWall = new QGraphicsRectItem();
    topWall->setRect(0, 0, SCENE_WIDTH, WALL_THICKNESS);
    topWall->setBrush(wallBrush);
    addItem(topWall);

    // Parede de Baixo
    QGraphicsRectItem *bottomWall = new QGraphicsRectItem();
    bottomWall->setRect(0, SCENE_HEIGHT - WALL_THICKNESS, SCENE_WIDTH, WALL_THICKNESS); // Ajusta a posição Y
    bottomWall->setBrush(wallBrush);
    addItem(bottomWall);

    // Define the boundaries for the paddles
    qreal topBoundary = WALL_THICKNESS;
    qreal bottomBoundary = SCENE_HEIGHT - WALL_THICKNESS - PADDLE_HEIGHT;

    // Raquete Player 1 (Left Paddle)
    qreal player1PaddleX = PADDLE_MARGIN;
    qreal player1PaddleY = ((SCENE_HEIGHT - (2  * WALL_THICKNESS))/2 - (PADDLE_HEIGHT / 2.0));
    // Create the paddle and give it its boundaries
    _player1Paddle = new Paddle(player1PaddleX, player1PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player1Paddle);

    // Definir Local Raquete 2 - Direita
    qreal player2PaddleX = SCENE_WIDTH - PADDLE_MARGIN - PADDLE_WIDTH;
    qreal player2PaddleY = ((SCENE_HEIGHT - (2  * WALL_THICKNESS))/2 - (PADDLE_HEIGHT / 2.0));

    // Criar Raquete 2 - Direita
    _player2Paddle = new Paddle(player2PaddleX, player2PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player2Paddle);

}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    // Player 1 - Left Paddle
    if (event->key() == Qt::Key_W) {
        _player1Paddle->moveUp();
    } else if (event->key() == Qt::Key_S) {
        _player1Paddle->moveDown();
    }

    // Player 2 - Right Paddle
    if (event->key() == Qt::Key_Up) {
        _player2Paddle->moveUp();
    } else if (event->key() == Qt::Key_Down) {
        _player2Paddle->moveDown();
    }

    QGraphicsScene::keyPressEvent(event);
}
