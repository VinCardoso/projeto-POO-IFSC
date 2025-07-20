#include "qtgraphics.h"
#include <QDebug> // Para mensagens de depuração

qtGraphics::qtGraphics(QWidget *parent)
    : QWidget(parent),
    m_gameIsRunning(false),
    m_isGameOver(false)
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
    m_scoreLabel->setGeometry(0, 0, width(), Constants::UI_HEADER_HEIGHT);

    m_messageLabel = new QLabel("", this);
    m_messageLabel->hide();

    // Chama o método para configurar o menu inicial
    setupMenu();

    // Rótulo para mensagens de jogo
    m_messageLabel = new QLabel("", this);
    m_messageLabel->setAlignment(Qt::AlignCenter);
    m_messageLabel->setFont(QFont("Arial", 28, QFont::Bold));
    m_messageLabel->setStyleSheet("color: red; background-color: transparent;");

    // Define uma altura fixa para o rótulo de mensagem
    m_messageLabel->setFixedHeight(Constants::UI_HEADER_HEIGHT / 2);
    mainLayout->addWidget(m_messageLabel);

    // Conecta os sinais da myScene aos slots da qtGraphics
    connect(m_myscene, &MyScene::scoreUpdated, this, &qtGraphics::updateScoreDisplay);
    connect(m_myscene, &MyScene::gameOver, this, &qtGraphics::handleGameOver);
    connect(m_myscene, &MyScene::repaintNeeded, this, &qtGraphics::requestRepaint);


    // Define as teclas de controle para os jogadores
    m_myscene->getPlayer1()->setControlKeys(Qt::Key_W, Qt::Key_S);
    m_myscene->getPlayer2()->setControlKeys(Qt::Key_Up, Qt::Key_Down);

}


qtGraphics::~qtGraphics(){}


// Evento responsável por desenhar o jogo.
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


void qtGraphics::keyPressEvent(QKeyEvent* event) {
    if (!m_gameIsRunning) { // Se o jogo não começou, não faz nada
        return;
    }

    // Lógica de Pausar o Jogo
    if (event->key() == Qt::Key_P) {
        // Só permite pausar/continuar se o jogo não tiver acabado
        if (!m_isGameOver) {
            m_myscene->togglePause();
            if (m_myscene->isPaused()) {
                m_messageLabel->setText("PAUSADO");
                m_messageLabel->setGeometry(0, height()/2 - 30, width(), 60);
                m_messageLabel->show();
            } else {
                m_messageLabel->hide();
            }
        }
        return; // Retorna para não processar outras teclas
    }

    // Lógica para reiniciar e sair (continua igual)
    if (event->key() == Qt::Key_R) {
        m_isGameOver = false;
        m_myscene->resetGame();
        m_messageLabel->hide();
        m_myscene->resume();
    } else if (event->key() == Qt::Key_Escape) {
        // Fechar Jogo
        close();
    }

    // Se o jogo estiver pausado (e não for a tecla P), ignora os movimentos
    if (m_myscene->isPaused()) {
        return;
    }

    if (m_playerCount == 2) {
        // Teclas para modo 2 Jogadores
        if (event->key() == m_myscene->getPlayer1()->getMoveUpKey()) {
            m_myscene->getPlayer1Paddle()->setMovingUp(true);
        } else if (event->key() == m_myscene->getPlayer1()->getMoveDownKey()) {
            m_myscene->getPlayer1Paddle()->setMovingDown(true);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
            m_myscene->getPlayer2Paddle()->setMovingUp(true);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
            m_myscene->getPlayer2Paddle()->setMovingDown(true);
        }
    } else { // Teclas para modo 1 Jogadores
        // As teclas do jogador 2 (Cima/Baixo) move AMBAS as raquetes
        if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
            m_myscene->getPlayer1Paddle()->setMovingUp(true);
            m_myscene->getPlayer2Paddle()->setMovingUp(true);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
            m_myscene->getPlayer1Paddle()->setMovingDown(true);
            m_myscene->getPlayer2Paddle()->setMovingDown(true);
        }
    }

}

// Lógica para mudar estado quando soltar botões
void qtGraphics::keyReleaseEvent(QKeyEvent* event) {
    if (!m_gameIsRunning) {
        return;
    }

    if (m_playerCount == 2) {
        // Teclas para modo 2 Jogadores
        if (event->key() == m_myscene->getPlayer1()->getMoveUpKey()) {
            m_myscene->getPlayer1Paddle()->setMovingUp(false);
        } else if (event->key() == m_myscene->getPlayer1()->getMoveDownKey()) {
            m_myscene->getPlayer1Paddle()->setMovingDown(false);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
            m_myscene->getPlayer2Paddle()->setMovingUp(false);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
            m_myscene->getPlayer2Paddle()->setMovingDown(false);
        }
    } else { // Teclas para modo 1 Jogadores
        if (event->key() == m_myscene->getPlayer2()->getMoveUpKey()) {
            m_myscene->getPlayer1Paddle()->setMovingUp(false);
            m_myscene->getPlayer2Paddle()->setMovingUp(false);
        } else if (event->key() == m_myscene->getPlayer2()->getMoveDownKey()) {
            m_myscene->getPlayer1Paddle()->setMovingDown(false);
            m_myscene->getPlayer2Paddle()->setMovingDown(false);
        }
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

void qtGraphics::setupMenu() {
    m_titleLabel = new QLabel("PONG", this);
    m_titleLabel->setAlignment(Qt::AlignCenter);
    m_titleLabel->setFont(QFont("Arial", 50, QFont::Bold));
    m_titleLabel->setStyleSheet("color: white;");
    m_titleLabel->setGeometry(0, height()/2 - 100, width(), 100);

    m_onePlayerButton = new QPushButton("1 Jogador", this);
    m_onePlayerButton->setFont(QFont("Arial", 16));
    m_onePlayerButton->setGeometry(width()/2 - 100, height()/2 + ((Constants::SCENE_HEIGHT/5)*2 - 50), 200, 40);

    m_twoPlayerButton = new QPushButton("2 Jogadores", this);
    m_twoPlayerButton->setFont(QFont("Arial", 16));
    m_twoPlayerButton->setGeometry(width()/2 - 100, height()/2 + (Constants::SCENE_HEIGHT/5)*2, 200, 40);

    // Conecta o sinal de clique de cada botão ao seu respectivo slot
    connect(m_onePlayerButton, &QPushButton::clicked, this, &qtGraphics::onOnePlayerClicked);
    connect(m_twoPlayerButton, &QPushButton::clicked, this, &qtGraphics::onTwoPlayerClicked);

    m_titleLabel->show();
    m_onePlayerButton->show();
    m_twoPlayerButton->show();
}

void qtGraphics::onOnePlayerClicked() {
    startGameMode(1);
}

void qtGraphics::onTwoPlayerClicked() {
    startGameMode(2);
}

void qtGraphics::startGameMode(int playerCount) {
    m_playerCount = playerCount;
    m_gameIsRunning = true;

    // Esconde os elementos do menu
    m_titleLabel->hide();
    m_onePlayerButton->hide();
    m_twoPlayerButton->hide();

    // Mostra o placar
    m_scoreLabel->show();

    // Define as teclas de controle
    m_myscene->getPlayer1()->setControlKeys(Qt::Key_W, Qt::Key_S);
    m_myscene->getPlayer2()->setControlKeys(Qt::Key_Up, Qt::Key_Down);

    // Inicia a lógica e o timer do jogo
    m_myscene->resume();
}
