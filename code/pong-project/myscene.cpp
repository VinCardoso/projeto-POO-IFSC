#include "myscene.h"
#include <QDebug>
#include <QPointF>

MyScene::MyScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(Qt::black); // Cor do fundo
    QBrush wallBrush(Qt::darkGray); // Cor dos itens;

    // Parede de Cima
        QGraphicsRectItem *topWall = new QGraphicsRectItem();
        topWall->setRect(0, 0, Constants::SCENE_WIDTH, Constants::WALL_THICKNESS);
        topWall->setBrush(wallBrush);
        addItem(topWall);

    // Parede de Baixo
        QGraphicsRectItem *bottomWall = new QGraphicsRectItem();
        bottomWall->setRect(0, Constants::SCENE_HEIGHT - Constants::WALL_THICKNESS, Constants::SCENE_WIDTH, Constants::WALL_THICKNESS);
        bottomWall->setBrush(wallBrush);
        addItem(bottomWall);

    // Gol - Lado Esqerdo
        QGraphicsRectItem *golEsq = new QGraphicsRectItem();
        golEsq->setRect(0, Constants::WALL_THICKNESS, Constants::GOAL_WIDTH, Constants::SCENE_HEIGHT - 2 * Constants::WALL_THICKNESS);
        golEsq->setBrush(wallBrush);
        addItem(golEsq);

    // Gol - Lado Direito
        QGraphicsRectItem *golDir = new QGraphicsRectItem();
        golDir->setRect(Constants::SCENE_WIDTH - Constants::GOAL_WIDTH, Constants::WALL_THICKNESS, Constants::GOAL_WIDTH, Constants::SCENE_HEIGHT - 2 * Constants::WALL_THICKNESS);
        golDir->setBrush(wallBrush);
        addItem(golDir);


    // Definir Local Raquete 1 - Esquerda
        qreal player1PaddleX = Constants::PADDLE_MARGIN;
        qreal player1PaddleY = ((Constants::SCENE_HEIGHT - (2  * Constants::WALL_THICKNESS))/2 - (Constants::PADDLE_HEIGHT / 2.0));

    // Criar Raquete 1 - Esquerda
        _player1Paddle = new Paddle(player1PaddleX, player1PaddleY, Constants::PADDLE_WIDTH, Constants::PADDLE_HEIGHT);
        addItem(_player1Paddle);

    // Definir Local Raquete 2 - Direita
        qreal player2PaddleX = Constants::SCENE_WIDTH - Constants::PADDLE_MARGIN - Constants::PADDLE_WIDTH;
        qreal player2PaddleY = ((Constants::SCENE_HEIGHT - (2  * Constants::WALL_THICKNESS))/2 - (Constants::PADDLE_HEIGHT / 2.0));

    // Criar Raquete 2 - Direita
        _player2Paddle = new Paddle(player2PaddleX, player2PaddleY, Constants::PADDLE_WIDTH, Constants::PADDLE_HEIGHT);
        addItem(_player2Paddle);

    // Adicionar Bola
        _ball = new Ball();
        _ball->setPos(Constants::SCENE_WIDTH / 2.0 - _ball->rect().width() / 2.0, Constants::SCENE_HEIGHT / 2.0 - _ball->rect().height() / 2.0);
        addItem(_ball);

    // Criar o timer para bola
        _timer = new QTimer(this);
        connect(_timer, &QTimer::timeout, _ball, &Ball::move);
        _timer->start(16); // Atualiza a cada ~16ms

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
