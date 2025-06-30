#include "qtgraphics.h"
#include <QGraphicsRectItem>

qtGraphics::qtGraphics(QWidget *parent)
    : QWidget(parent)
{
    _scene = new MyScene;
    _view = new QGraphicsView(_scene);

    _layout = new QVBoxLayout();
    _layout->addWidget(_view);

    setLayout(_layout);
    setWindowTitle("Pong Game - Vinicius");
}

qtGraphics::~qtGraphics() {}
