#include "myscene.h"
#include <QDebug>
#include <QPointF>

// Construtor da cena do jogo.
MyScene::MyScene(QObject *parent)
    : QObject(parent),
    m_ball(nullptr),
    m_player1Paddle(nullptr),
    m_player2Paddle(nullptr),
    m_topWall(nullptr),
    m_bottomWall(nullptr),
    m_goal1(nullptr),
    m_goal2(nullptr),
    m_player1(nullptr),
    m_player2(nullptr) {

    // Configura o timer do jogo.
    m_gameTimer = new QTimer(this);

    // Conecta o sinal timeout do timer ao slot updateGame.
    connect(m_gameTimer, &QTimer::timeout, this, &MyScene::updateGame);

    initializeGameObjects(); // Cria e configura todos os objetos do jogo
}

MyScene::~MyScene(){}

// Inicializa todos os objetos do jogo.
void MyScene::initializeGameObjects() {

    // Cria os jogadores
    m_player1 = new player(this);
    m_player2 = new player(this);

    // Cria as raquetes
    m_player1Paddle = new Paddle(1, QPointF(Constants::PADDLE_MARGIN, (Constants::SCENE_HEIGHT - Constants::PADDLE_SIZE.height()) / 2));
    m_player2Paddle = new Paddle(2, QPointF(Constants::SCENE_WIDTH - Constants::PADDLE_MARGIN - Constants::PADDLE_SIZE.width(), (Constants::SCENE_HEIGHT - Constants::PADDLE_SIZE.height()) / 2));

    // Associa as raquetes aos jogadores
    m_player1->setPaddle(m_player1Paddle);
    m_player2->setPaddle(m_player2Paddle);

    // Define os limites de movimento das raquetes
    m_player1Paddle->setMovementBounds(Constants::WALL_THICKNESS, Constants::SCENE_HEIGHT - Constants::WALL_THICKNESS);
    m_player2Paddle->setMovementBounds(Constants::WALL_THICKNESS, Constants::SCENE_HEIGHT - Constants::WALL_THICKNESS);

    // Cria as paredes superior e inferior
    m_topWall = new wall(QPointF(0, 0), QSizeF(Constants::SCENE_WIDTH, Constants::WALL_THICKNESS));
    m_bottomWall = new wall(QPointF(0, Constants::SCENE_HEIGHT - Constants::WALL_THICKNESS), QSizeF(Constants::SCENE_WIDTH, Constants::WALL_THICKNESS));

    // Cria os gols
    m_goal1 = new goal(2, QPointF(0, 0), QSizeF(Constants::GOAL_WIDTH, Constants::SCENE_HEIGHT)); // Gol do Player 1, ponto para Player 2
    m_goal2 = new goal(1, QPointF(Constants::SCENE_WIDTH - Constants::GOAL_WIDTH, 0), QSizeF(Constants::GOAL_WIDTH, Constants::SCENE_HEIGHT)); // Gol do Player 2, ponto para Player 1

    // Cria a bola
    m_ball = new Ball();

    // Adiciona todos os objetos à lista
    m_gameObjects.append(m_topWall);
    m_gameObjects.append(m_bottomWall);
    m_gameObjects.append(m_goal1);
    m_gameObjects.append(m_goal2);
    m_gameObjects.append(m_player1Paddle);
    m_gameObjects.append(m_player2Paddle);
    m_gameObjects.append(m_ball);
}

// Inicia o loop do jogo.
void MyScene::startGame() {
    m_elapsedTimer.start(); // Inicia o timer para calcular o deltaTime
    m_gameTimer->start(1000 / 60); // Inicia o timer para 60 FPS (aproximadamente 16ms por frame)
    qDebug() << "Jogo iniciado!";
}

// Reinicia o jogo para o estado inicial.
void MyScene::resetGame() {
    m_ball->reset(); // Reinicia a bola
    m_player1->resetScore(); // Reseta a pontuação dos jogadores
    m_player2->resetScore();
    m_player1Paddle->setPosition(QPointF(Constants::PADDLE_MARGIN, (Constants::SCENE_HEIGHT - Constants::PADDLE_SIZE.height()) / 2));
    m_player2Paddle->setPosition(QPointF(Constants::SCENE_WIDTH - Constants::PADDLE_MARGIN - Constants::PADDLE_SIZE.width(), (Constants::SCENE_HEIGHT - Constants::PADDLE_SIZE.height()) / 2));
    emit scoreUpdated(m_player1->getScore(), m_player2->getScore()); // Atualiza a exibição da pontuação
    qDebug() << "Jogo resetado.";
}

// Retorna a lista de todos os objetos do jogo.
const QList<game_object*>& MyScene::getAllGameObjects() const {
    return m_gameObjects;
}

// Retorna o objeto Ball.
Ball* MyScene::getBall() const {
    return m_ball;
}

// Retorna as raquetes dos jogadores.
Paddle* MyScene::getPlayer1Paddle() const {
    return m_player1Paddle;
}

Paddle* MyScene::getPlayer2Paddle() const {
    return m_player2Paddle;
}

// Retorna os objetos Player.
player* MyScene::getPlayer1() const {
    return m_player1;
}

player* MyScene::getPlayer2() const {
    return m_player2;
}

// Slot principal do loop do jogo.
void MyScene::updateGame() {
    qint64 deltaTime = m_elapsedTimer.restart(); // Calcula o tempo decorrido desde a última chamada

    // Atualiza todos os objetos do jogo.
    m_ball->update(deltaTime);
    m_player1Paddle->update(deltaTime);
    m_player2Paddle->update(deltaTime);

    handleCollisions(); // Verifica e trata as colisões
    checkGoals();       // Verifica se houve um gol

    // Emite um sinal para a qtGraphics para que ela se redesenhe.
    emit repaintNeeded();
}

// Gerencia as colisões entre a bola e outros objetos.
void MyScene::handleCollisions() {

    // Colisão com paredes superior e inferior
    if (m_ball->getRect().intersects(m_topWall->getRect()) ||
        m_ball->getRect().intersects(m_bottomWall->getRect())) {
        m_ball->deflectY();

        // Ajusta a posição da bola para evitar que ela "grude" na parede
        if (m_ball->getRect().top() < m_topWall->getRect().bottom()) {
            m_ball->setPosition(QPointF(m_ball->getPosition().x(), m_topWall->getRect().bottom()));
        } else if (m_ball->getRect().bottom() > m_bottomWall->getRect().top()) {
            m_ball->setPosition(QPointF(m_ball->getPosition().x(), m_bottomWall->getRect().top() - m_ball->getSize().height()));
        }
    }

    // Colisão com raquetes
    if (m_ball->getRect().intersects(m_player1Paddle->getRect())) {

        // Verifica se a bola está vindo na direção da raquete (para evitar múltiplas colisões)
        if (m_ball->getVelocity().x() < 0) {
            m_ball->deflectX();
            m_ball->increaseSpeed();

            // Ajusta a posição da bola para evitar que ela "grude" na raquete
            m_ball->setPosition(QPointF(m_player1Paddle->getRect().right(), m_ball->getPosition().y()));
        }

    } else if (m_ball->getRect().intersects(m_player2Paddle->getRect())) {

        // Verifica se a bola está vindo na direção da raquete
        if (m_ball->getVelocity().x() > 0) {
            m_ball->deflectX();
            m_ball->increaseSpeed();

            // Ajusta a posição da bola
            m_ball->setPosition(QPointF(m_player2Paddle->getRect().left() - m_ball->getSize().width(), m_ball->getPosition().y()));
        }
    }
}

// Verifica se a bola atingiu um gol.
void MyScene::checkGoals() {

    if (m_ball->getRect().intersects(m_goal1->getRect())) {

        // Bola atingiu o gol do Player 1, ponto para o Player 2
        m_player2->increaseScore();
        qDebug() << "Gol! Player 2: " << m_player2->getScore();
        emit scoreUpdated(m_player1->getScore(), m_player2->getScore());
        m_ball->reset(); // Reinicia a bola

    } else if (m_ball->getRect().intersects(m_goal2->getRect())) {

        // Bola atingiu o gol do Player 2, ponto para o Player 1
        m_player1->increaseScore();
        qDebug() << "Gol! Player 1: " << m_player1->getScore();
        emit scoreUpdated(m_player1->getScore(), m_player2->getScore());
        m_ball->reset(); // Reinicia a bola

    }
}
