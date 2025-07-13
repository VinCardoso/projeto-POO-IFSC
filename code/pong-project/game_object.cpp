#include "game_object.h"

game_object::game_object(const QPointF& position, const QSizeF& size)
    : o_position(position), o_size(size)
{}

// Retorna o retângulo que representa a área do objeto para detecção de colisão
QRectF game_object::getRect() const {
    return QRectF(o_position, o_size);
}


// Define a nova posição do objeto.
void game_object::setPosition(const QPointF& position) {
    o_position = position;
}

// Retorna a posição atual do objeto.
QPointF game_object::getPosition() const {
    return o_position;
}

// Define novo tamanho do objeto.
void game_object::setSize(const QSizeF& size) {
    o_size = size;
}

// Retorna o tamanho atual do objeto.
QSizeF game_object::getSize() const {
    return o_size;
}
