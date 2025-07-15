#ifndef QTGRAPHICS_H
#define QTGRAPHICS_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

#include "constants.h"
#include "myscene.h"

class qtGraphics : public QWidget
{
    Q_OBJECT

public:
    // Construtor da janela do jogo.
    qtGraphics(QWidget* parent = nullptr);

    // Destrutor.
    ~qtGraphics();

protected:

    // Evento de pintura, onde o jogo é desenhado.
    void paintEvent(QPaintEvent* event) override;

    // Evento de pressionar tecla.
    void keyPressEvent(QKeyEvent* event) override;

    // Evento de soltar tecla.
    void keyReleaseEvent(QKeyEvent* event) override;

private slots:

    // Slot para atualizar a exibição da pontuação.
    void updateScoreDisplay(int player1Score, int player2Score);

    // Slot para lidar com o fim do jogo.
    void handleGameOver(int winnerPlayerID);

    // Slot para forçar a repintura da janela (conectado ao sinal de GameScene).
    void requestRepaint();

    void onOnePlayerClicked(); // Slot para o clique no botão "1 Jogador"
    void onTwoPlayerClicked(); // Slot para o clique no botão "2 Jogadores"

private:
    void setupMenu();      // Método para criar e exibir o menu inicial
    void startGameMode(int playerCount); // Método para iniciar o jogo com o modo selecionado

    MyScene* m_myscene; // A cena do jogo que contém a lógica e os objetos
    QLabel* m_scoreLabel;   // Rótulo para exibir a pontuação
    QLabel* m_messageLabel; // Rótulo para exibir mensagens de jogo

    int m_playerCount; // Guarda o número de jogadores (1 ou 2)
    bool m_gameIsRunning; // Controla se o jogo está ativo ou não
    bool m_isGameOver; // Vê se o jogo já acabou ou não

    // Elementos da UI do Menu
    QLabel* m_titleLabel;
    QPushButton* m_onePlayerButton;
    QPushButton* m_twoPlayerButton;
};

#endif // QTGRAPHICS_H
