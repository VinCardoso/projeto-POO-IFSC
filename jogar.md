# Caso de Uso: Jogar Pong

## Objetivo:
Descrever a lógica principal de uma partida de Pong, na qual dois jogadores controlam raquetes para rebater uma bola e marcar pontos.

## Requisitos
- RF1: Iniciar e executar uma partida de Pong.
- RF2: Registrar a pontuação de cada jogador.
- RF3: Detectar colisões da bola com raquetes e limites da tela.

## Atores
- Jogador 1 
- Jogador 2 

## Prioridade
Não se aplica.

## Pré-condições
- As raquetes e a bola devem estar posicionadas na posição inicial.
- O placar deve começar em 0-0.

## Frequência de Uso
Não se aplica.

## Criticidade
Não se aplica.

## Condição de Entrada
O jogador pressiona a tecla Enter para o início de uma nova partida.

## Fluxo Principal

### Inicialização:
- Instancia dois objetos Paddle e um objeto Ball.
- Zera o placar e coloca os elementos nas posições iniciais.

### Loop de Jogo: Ocorre enquanto nenhum jogador atingir 5 pontos.
- Detecção: O sistema detecta colisões e ajusta a direção da bola.
- Pontuação: O jogador correspondente pontua.
- Verificação de Término: O sistema exibe uma mensagem de vencedor quando um jogador atinge 5 pontos e encerra o loop.

## Fluxo Alternativo
Se o jogador pausar o jogo (tecla P), o loop do jogo é suspenso até ser despausado.

## Pós-condições
A partida foi finalizada.
O vencedor foi registrado.
As estatísticas de placar foram atualizadas.

## Regras de Negócio
- A partida é vencida ao alcançar 5 pontos.
- A cada 2 pontos marcados, a velocidade da bola aumenta.
- As raquetes têm tamanho e velocidade fixos e não podem sair da área visível.



<div align="center">

[Retroceder](analise.md)

</div>