#include "qtgraphics.h"
#include <QDebug> // Para mensagens de depuração
#include <QMessageBox> // Para exibir mensagens ao usuário

qtGraphics::qtGraphics(QWidget *parent)
    : QWidget(parent)
{
    // A altura total da janela será a altura da UI + a altura da cena do jogo.
    setFixedSize(Constants::SCENE_WIDTH, Constants::SCENE_HEIGHT + Constants::UI_HEADER_HEIGHT);
    setWindowTitle("Pong Game - Vinicius IFSC");

    // Cria a cena do jogo.
    m_myscene = new MyScene(this);

    // Cria o layout principal
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Remove margens padrão

    // Rótulo para a pontuação
    m_scoreLabel = new QLabel("0 - 0", this);
    m_scoreLabel->setAlignment(Qt::AlignCenter);
    m_scoreLabel->setFont(QFont("Arial", 24, QFont::Bold));
    m_scoreLabel->setStyleSheet("color: white; background-color: #333; padding: 5px;");

    // Define uma altura fixa para o rótulo da pontuação para controlar o layout
    m_scoreLabel->setFixedHeight(Constants::UI_HEADER_HEIGHT / 2);
    // mainLayout->addWidget(m_scoreLabel);

    // Rótulo para mensagens de jogo
    m_messageLabel = new QLabel("", this);
    m_messageLabel->setAlignment(Qt::AlignCenter);
    m_messageLabel->setFont(QFont("Arial", 28, QFont::Bold));
    m_messageLabel->setStyleSheet("color: red; background-color: transparent;");

    // Define uma altura fixa para o rótulo de mensagem
    m_messageLabel->setFixedHeight(Constants::UI_HEADER_HEIGHT / 2);
    mainLayout->addWidget(m_messageLabel);
    m_messageLabel->hide(); // Esconde inicialmente

    // Conecta os sinais da myScene aos slots da qtGraphics
    connect(m_myscene, &MyScene::scoreUpdated, this, &qtGraphics::updateScoreDisplay);
    connect(m_myscene, &MyScene::gameOver, this, &qtGraphics::handleGameOver);
    connect(m_myscene, &MyScene::repaintNeeded, this, &qtGraphics::requestRepaint);


    // Define as teclas de controle para os jogadores
    m_myscene->getPlayer1()->setControlKeys(Qt::Key_W, Qt::Key_S);
    m_myscene->getPlayer2()->setControlKeys(Qt::Key_Up, Qt::Key_Down);

    // Inicia o jogo
    m_myscene->startGame();
}


qtGraphics::~qtGraphics(){}


// Evento de pintura, responsável por desenhar o jogo.
void qtGraphics::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Desenha o fundo do jogo (área do jogo, excluindo a área da pontuação)
    painter.fillRect(0, Constants::UI_HEADER_HEIGHT, Constants::SCENE_WIDTH, Constants::SCENE_HEIGHT, Qt::black);

    // Desenha todos os objetos da cena do jogo.
    for (game_object* obj : m_myscene->getAllGameObjects()) {
        painter.save(); // Salva o estado atual do pintor
        // Translada o pintor para desenhar os objetos abaixo da área de score/message
        painter.translate(0, Constants::UI_HEADER_HEIGHT);
        obj->draw(&painter);
        painter.restore(); // Restaura o estado anterior do pintor
    }

    // Desenha a linha central do campo
    painter.setPen(QPen(Qt::gray, 1, Qt::DashLine));
    painter.drawLine(Constants::SCENE_WIDTH / 2, Constants::UI_HEADER_HEIGHT,
                     Constants::SCENE_WIDTH / 2, Constants::SCENE_HEIGHT + Constants::UI_HEADER_HEIGHT);
}

// Evento de pressionar tecla.
void qtGraphics::keyPressEvent(QKeyEvent* event) {

    // Player 1
    if (event->key() == m_myscene->getPlayer1()->getMoveUpKey()) {
        m_myscene->getPlayer1Paddle()->setMovingUp(true);
    } else if (event->key() == m_myscene->getPlayer1()->getMoveDownKey()) {
        m_myscene->getPlayer1Paddle()->setMovingDown(true);
    }

    // Player 2
    else if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
        m_myscene->getPlayer2Paddle()->setMovingUp(true);
    } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
        m_myscene->getPlayer2Paddle()->setMovingDown(true);
    }

    // Reiniciar o jogo (ex: tecla R)
    else if (event->key() == Qt::Key_R) {
        m_myscene->resetGame();
        m_messageLabel->hide(); // Esconde a mensagem de Game Over
        m_myscene->startGame(); // Reinicia o loop do jogo
    }

    // Sair do jogo (ex: tecla Esc)
    else if (event->key() == Qt::Key_Escape) {
        close(); // Fecha a janela
    }
}

// Evento de soltar tecla.
void qtGraphics::keyReleaseEvent(QKeyEvent* event) {

    // Player 1
    if (event->key() == m_myscene->getPlayer1()->getMoveUpKey()) {
        m_myscene->getPlayer1Paddle()->setMovingUp(false);
    } else if (event->key() == m_myscene->getPlayer1()->getMoveDownKey()) {
        m_myscene->getPlayer1Paddle()->setMovingDown(false);
    }

    // Player 2
    else if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
        m_myscene->getPlayer2Paddle()->setMovingUp(false);
    } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
        m_myscene->getPlayer2Paddle()->setMovingDown(false);
    }
}

// Atualizar a exibição da pontuação.
void qtGraphics::updateScoreDisplay(int player1Score, int player2Score) {
    m_scoreLabel->setText(QString("%1 - %2").arg(player1Score).arg(player2Score));
}

// Fim do jogo.
void qtGraphics::handleGameOver(int winnerPlayerID) {
    QString message = QString("Player %1 Venceu! Pressione 'R' para Reiniciar.").arg(winnerPlayerID);
    m_messageLabel->setText(message);
    m_messageLabel->show(); // Exibe a mensagem de Game Over
    qDebug() << message;
}

// Forçar a reinstanciar da janela.
void qtGraphics::requestRepaint() {
    update(); // Chama paintEvent() para redesenhar a janela
}
