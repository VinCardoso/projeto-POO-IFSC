#ifndef WALL_H
#define WALL_H

#include "game_object.h"

class wall : public game_object
{
    Q_OBJECT
public:
    // Construtor da parede.
    wall(const QPointF& position, const QSizeF& size);

    // Paredes são estáticas, então não precisam de lógica de atualização.
    void update(qint64 deltaTime) override;

    // Desenha a parede na tela.
    void draw(QPainter* painter) override;
};

#endif // WALL_H
