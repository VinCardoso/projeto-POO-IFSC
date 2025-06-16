# Caso de Uso: Mover Bola

## Objetivo:
Fazar a movimentação da raquetes;

## Requisitos:
- RF1: Saber se tem 1 ou 2 jogadores;
- RF2: Mover raquetes em conjunto;
- RF3: Mover raquetes de forma independente;

## Atores:
- Raquete 1;
- Raquete 2;

## Prioridade:
Não se Aplica

## Pré-Condições:
- Inicia o jogo já com 1 ou 2 jogadores;

## Frequência de Uso:
Não se aplica;

## Criticidade:
Não se Aplica

## Fluxo Principal:

### Loop do Jogo:
- Verifica o local atual de cada raquete;
- Se for 1 jogador ao mover a raquete move as duas ao mesmo tempo;
- Se for 2 jogadores, vão ter mais dois botões de controle e elas são movidas de forma idenpendente;

## Fluxo Alternativo:
Não se aplica

### Pós Condições:
Não se aplica

## Regras de Negócio
- Pode mover para cima e para baixo;
- Tem os limites da parete superior e inferior;
- Com um jogador usa as teclas ⬆ e ⬇, se tiver dois usa para o lado esquerdo as teclas W e S;