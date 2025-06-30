#include "myscene.h"
#include <QDebug>
// #include <QGraphicsSceneMouseEvent>
#include <QPointF>

// Variáveis
#define SCENE_WIDTH 800
#define SCENE_HEIGHT 400
#define WALL_THICKNESS 20
#define BALL_SIZE 20
#define PADDLE_WIDTH 20
#define PADDLE_HEIGHT 100
#define PADDLE_MARGIN 10


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

    // Raquete Player 1
    qreal player1PaddleX = PADDLE_MARGIN;
    qreal player1PaddleY = (SCENE_HEIGHT / 2.0) - (PADDLE_HEIGHT / 2.0); // Centraliza verticalmente
    _player1Paddle = new Paddle(player1PaddleX, player1PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player1Paddle);

    // Raquete Player 2
    qreal player2PaddleX = SCENE_WIDTH - PADDLE_MARGIN - PADDLE_WIDTH;
    qreal player2PaddleY = (SCENE_HEIGHT / 2.0) - (PADDLE_HEIGHT / 2.0); // Centraliza verticalmente
    _player2Paddle = new Paddle(player2PaddleX, player2PaddleY, PADDLE_WIDTH, PADDLE_HEIGHT);
    addItem(_player2Paddle);


    // _rect = addRect(QRectF(-50,-50,100,100));
    // _rect->setPos(QPointF(50,50));
    // _rect->setRotation(45);
    // QPen pen(Qt::red);
    // pen.setWidth(4);
    // _rect->setPen(pen);
    // _rect->setBrush(Qt::blue);
    // _rect->setFlag(QGraphicsItem::ItemIsFocusable);


    // _ball = new Ball(200,200,100,100);
    // _ball->setPen(pen);
    // _ball->setBrush(Qt::gray);
    // _ball->setFlag(QGraphicsItem::ItemIsFocusable);
    // _ball->setFlag(QGraphicsItem::ItemIsMovable);
    // addItem(_ball);


    // addLine(-200,0,200,0);
    // addLine(0,-200,0,200);


    // _timer = new QTimer;
    // QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(advance()));
    // _timer->start(1000/30);
}

// void MyScene::setupBall()
// {
//     // Calcula a posição central para a bola
//     // Lembre-se que setRect(x, y, width, height) define o canto superior esquerdo do retângulo que envolve a elipse.
//     // Para centralizar, subtraímos metade do tamanho da bola das coordenadas centrais da cena.
//     qreal ballX = (SCENE_WIDTH / 2.0) - (BALL_SIZE / 2.0);
//     qreal ballY = (SCENE_HEIGHT / 2.0) - (BALL_SIZE / 2.0);

//     // Cria a instância da bola
//     gameBall = new Ball(ballX, ballY, BALL_SIZE, BALL_SIZE);
//     addItem(gameBall); // Adiciona a bola à cena
// }

// void MyScene::keyPressEvent(QKeyEvent *event)
// {
//     qDebug() << "Key press event in MyScene";

//     QGraphicsItem * item = this->focusItem();
//     if(item == nullptr){
//         qDebug() << "No item in focus!";
//     } else {
//         if( event->key() == Qt::Key_Left) {
//             item->moveBy(-1,0);
//         }
//         if( event->key() == Qt::Key_Right) {
//             item->moveBy(1,0);
//         }
//         if( event->key() == Qt::Key_Up) {
//             item->moveBy(0,-1);
//         }
//         if( event->key() == Qt::Key_Down) {
//             item->moveBy(0,1);
//         }
//     }
//     // QGraphicsScene::keyPressEvent(event);
// }

// void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
// {
//     QPointF pos = event->scenePos();
//     _ball->setTarget(pos);
//     qDebug() << "Clicked in " << pos.x() << "," << pos.y();
// }
