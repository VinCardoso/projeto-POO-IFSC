#include "wall.h"

wall::wall(const QPointF& position, const QSizeF& size)
    : game_object(position, size) {
}

// Paredes não têm lógica de atualização, pois são estáticas.
void wall::update(qint64 deltaTime) {
    Q_UNUSED(deltaTime); // Indica que o parâmetro não será usado para evitar warnings.
}

// Desenha a parede como um retângulo.
void wall::draw(QPainter* painter) {
    painter->setBrush(Qt::gray); // Cor da parede
    painter->setPen(Qt::NoPen);  // Sem borda
    painter->drawRect(getRect()); // Desenha a parede
}
