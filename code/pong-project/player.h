#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include "paddle.h"

class player : public QObject
{
    Q_OBJECT

public:
    // Construtor do jogador.
    explicit player(QObject *parent = nullptr);

    // Adicionar Pontos ao Jogador
    void increaseScore();

    // Pegar a pontuação atual do Jogador
    int getScore() const;

    // Zerar os pontos do Jogador
    void resetScore();

    // Associa a Raquete do Jogador
    void setPaddle(Paddle* paddle);

    // Retorna a Raquete Associada
    Paddle* getPaddle() const;

    // Defini as teclas para movimentar a raquete
    void setControlKeys(Qt::Key upKey, Qt::Key downKey);
    Qt::Key getMoveUpKey() const;
    Qt::Key getMoveDownKey() const;

private:
    int p_score;         // Pontuação do jogador
    Paddle* p_paddle;    // Ponteiro para a raquete controlada por este jogador
    Qt::Key p_moveUpKey;   // Tecla para mover a raquete para cima
    Qt::Key p_moveDownKey; // Tecla para mover a raquete para baixo

};

#endif // PLAYER_H
