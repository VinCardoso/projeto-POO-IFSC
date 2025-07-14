#include "goal.h"

goal::goal(int playerScoringID, const QPointF& position, const QSizeF& size)
    : game_object(position, size),
    m_playerScoringID(playerScoringID) {
}

// Gols não têm lógica de atualização
void goal::update(qint64 deltaTime) {
    Q_UNUSED(deltaTime);
}

// Desenha o gol
void goal::draw(QPainter* painter) {
    painter->setPen(QPen(Qt::white, 2));
    qreal lineX = o_position.x() + o_size.width() / 2.0;
    painter->drawLine(QPointF(lineX, o_position.y()), QPointF(lineX, o_position.y() + o_size.height()));
}

// Retorna o ID do jogador que pontua ao atingir este gol.
int goal::getPlayerScoringID() const {
    return m_playerScoringID;
}
