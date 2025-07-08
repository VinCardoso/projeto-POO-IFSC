#include "myscene.h"
#include <QDebug>
#include <QPointF>


// Variáveis
#define SCENE_WIDTH 800
#define SCENE_HEIGHT 400
#define WALL_THICKNESS 20
#define GOAL_WIDTH 5

#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_MARGIN 15


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
    bottomWall->setRect(0, SCENE_HEIGHT - WALL_THICKNESS, SCENE_WIDTH, WALL_THICKNESS);
    bottomWall->setBrush(wallBrush);
    addItem(bottomWall);

    // Gol - Lado Esqerdo
    QGraphicsRectItem *golEsq = new QGraphicsRectItem();
    golEsq->setRect(0, WALL_THICKNESS, GOAL_WIDTH, SCENE_HEIGHT - 2 * WALL_THICKNESS);
    golEsq->setBrush(wallBrush);
    addItem(golEsq);

    // Gol - Lado Direito
    QGraphicsRectItem *golDir = new QGraphicsRectItem();
    golDir->setRect(SCENE_WIDTH - GOAL_WIDTH, WALL_THICKNESS, GOAL_WIDTH, SCENE_HEIGHT - 2 * WALL_THICKNESS);
    golDir->setBrush(wallBrush);
    addItem(golDir);


    // Definir Local Raquete 1 - Esquerda
    qreal player1PaddleX = PADDLE_MARGIN;
    qreal player1PaddleY = ((SCENE_HEIGHT - (2  * WALL_THICKNESS))/2 - (PADDLE_HEIGHT / 2.0));

    // Criar Raquete 1 - Esquerda
    _player1Paddle = new Paddle(player1PaddleX, player1PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player1Paddle);

    // Definir Local Raquete 2 - Direita
    qreal player2PaddleX = SCENE_WIDTH - PADDLE_MARGIN - PADDLE_WIDTH;
    qreal player2PaddleY = ((SCENE_HEIGHT - (2  * WALL_THICKNESS))/2 - (PADDLE_HEIGHT / 2.0));

    // Criar Raquete 2 - Direita
    _player2Paddle = new Paddle(player2PaddleX, player2PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player2Paddle);

    // Adicionar Bola
    _ball = new Ball();
    _ball->setPos(SCENE_WIDTH / 2.0 - _ball->rect().width() / 2.0, SCENE_HEIGHT / 2.0 - _ball->rect().height() / 2.0);
    addItem(_ball);

    // Criar o timer
    _timer = new QTimer(this);
    // Conecta o sinal de 'timeout' do timer ao slot 'move' da bola
    connect(_timer, &QTimer::timeout, _ball, &Ball::move);

    // 3. Iniciar o timer
    _timer->start(16); // Atualiza a cada ~16ms (~60 FPS)

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
