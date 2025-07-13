#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <QObject>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QPainter>

class game_object : public QObject
{
    Q_OBJECT
public:

    game_object(const QPointF& position, const QSizeF& size);

    // deltaTime: tempo decorrido desde a última atualização (em milissegundos).
    virtual void update (qint64 deltaTime) = 0;

    // painter: ponteiro para o QPainter usado para desenhar.
    virtual void draw(QPainter* painter) = 0;

    // Retorna o retângulo de colisão/desenho do objeto.
    QRectF getRect() const;

    // Define a posição do objeto.
    void setPosition(const QPointF& position);

    // Retorna a posição do objeto.
    QPointF getPosition() const;

    // Define o tamanho do objeto.
    void setSize(const QSizeF& size);

    // Retorna o tamanho do objeto.
    QSizeF getSize() const;


protected:
    QPointF o_position;
    QSizeF o_size;

signals:
};

#endif // GAME_OBJECT_H
