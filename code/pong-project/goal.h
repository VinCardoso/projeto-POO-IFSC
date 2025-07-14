#ifndef GOAL_H
#define GOAL_H

#include "game_object.h"

class goal : public game_object
{
    Q_OBJECT
public:

    // Construtor do gol

    // playerScoringID: ID do jogador que marca um ponto se a bola atingir este gol.
    goal(int playerScoringID, const QPointF& position, const QSizeF& size);

    // Gols são estáticos, não precisam de lógica de atualização.
    void update(qint64 deltaTime) override;

    // Desenha o gol na tela
    void draw(QPainter* painter) override;

    // Retorna o ID do jogador que marca um ponto neste gol.
    int getPlayerScoringID() const;

private:
    int m_playerScoringID; // ID do jogador que recebe o ponto
};

#endif // GOAL_H
