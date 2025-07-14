#include "player.h"

player::player(QObject *parent)
    : QObject{parent},
    p_score(0),
    p_paddle(nullptr),
    p_moveUpKey(Qt::Key_unknown),
    p_moveDownKey(Qt::Key_unknown)
{}

// Adicionar Pontos ao Jogador
void player::increaseScore(){
    p_score++;
}

// Pegar a pontuação atual
int player::getScore() const{
    return p_score;
}

// Zerar os pontos do Jogador
void player::resetScore(){
    p_score = 0;
}

// Associa a Raquete do Jogador
void player::setPaddle(Paddle* paddle){
    p_paddle = paddle;
}

// Retorna a Raquete Associada
Paddle* player::getPaddle() const{
    return p_paddle;
}

// Defini as teclas para movimentar a raquete
void player::setControlKeys(Qt::Key upKey, Qt::Key downKey) {
    p_moveUpKey = upKey;
    p_moveDownKey = downKey;
}

Qt::Key player::getMoveUpKey() const {
    return p_moveUpKey;
}

Qt::Key player::getMoveDownKey() const {
    return p_moveDownKey;
}

