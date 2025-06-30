#ifndef QTGRAPHICS_H
#define QTGRAPHICS_H

#include <QWidget>
#include <QGraphicsView>
#include <QVBoxLayout>
#include "myscene.h"

class qtGraphics : public QWidget
{
    Q_OBJECT

    MyScene * _scene;
    QGraphicsView * _view;
    QVBoxLayout * _layout;
public:
    qtGraphics(QWidget *parent = nullptr);
    ~qtGraphics();
};
#endif // QTGRAPHICS_H
