#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QSizeF>

namespace Constants {

    // Dimensões da tela
    const int SCENE_WIDTH = 800;
    const int SCENE_HEIGHT = 400;

    // Dimensão da parte de interface superior
    const int UI_HEADER_HEIGHT = 60;

    // Tamanho da Raquete
    const QSizeF PADDLE_SIZE = QSizeF(15, 100);

    // Velocidade da raquete (pixels por segundo);
    const qreal PADDLE_SPEED = 400;

    // Margem das raquetes em relação a bordas laterais
    const qreal PADDLE_MARGIN = 10;

    // Tamanho da bola
    const QSizeF BALL_SIZE = QSizeF(20, 20);

    // Velocidade inicial da bola (pixels por segundo)
    const qreal BALL_INITIAL_SPEED = 300;

    // Aumento de velocidade da bola a cada rebatida
    const qreal BALL_SPEED_INCREASE_FACTOR = 1.05;

    // Paredes (Cima e Baixo)
    const int WALL_THICKNESS = 10;

    // Espessura do Gol (Direito e Esquerdo)
    const int GOAL_WIDTH = 2;

    // Pontuação necessária para vencer o jogo
    const int WINNING_SCORE = 5;

}

#endif // CONSTANTS_H
