#ifndef MYSCENE_H
#define MYSCENE_H

#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QElapsedTimer>

#include "ball.h"
#include "paddle.h"
#include "player.h"
#include "wall.h"
#include "goal.h"
#include "constants.h"

class MyScene : public QObject
{
    Q_OBJECT

public:

    // Construtor da cena do jogo.

    explicit MyScene(QObject *parent = nullptr);

    // Destrutor. Limpa os objetos do jogo.
    ~MyScene();

    // Inicia o loop do jogo.
    void startGame();

    // Reinicia o jogo para o estado inicial.
    void resetGame();

    // Retorna a lista de todos os objetos do jogo para desenho.
    const QList<game_object*>& getAllGameObjects() const;

    // Retorna o objeto Ball.
    Ball* getBall() const;

    // Retorna os objetos Paddle.
    Paddle* getPlayer1Paddle() const;
    Paddle* getPlayer2Paddle() const;

    // Retorna os objetos Player.
    player* getPlayer1() const;
    player* getPlayer2() const;

signals:

    // Sinal emitido quando a pontuação é atualizada.
    void scoreUpdated(int player1Score, int player2Score);

    // Sinal emitido quando o jogo termina (se a pontuação máxima for atingida).
    void gameOver(int winnerPlayerID);

    // Sinal para indicar que a cena precisa ser redesenhada.
    void repaintNeeded();

private slots:

    // Slot principal do loop do jogo, chamado pelo QTimer.
    void updateGame();

private:

    // Inicializa todos os objetos do jogo (bola, raquetes, paredes, gols).
    void initializeGameObjects();

    // Gerencia as colisões entre a bola e outros objetos.
    void handleCollisions();

    // Verifica se a bola atingiu um gol e atualiza a pontuação.
    void checkGoals();

    // Objetos do jogo
    Ball* m_ball;
    Paddle* m_player1Paddle;
    Paddle* m_player2Paddle;
    wall* m_topWall;
    wall* m_bottomWall;
    goal* m_goal1;
    goal* m_goal2;
    player* m_player1;
    player* m_player2;

    QList<game_object*> m_gameObjects; // Lista de todos os objetos para fácil iteração

    QTimer* m_gameTimer;        // Timer para o loop principal do jogo
    QElapsedTimer m_elapsedTimer; // Timer para calcular o tempo decorrido (deltaTime)
};

#endif // MYSCENE_H
