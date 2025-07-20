# Caso de Uso: Mover Bola

## Objetivo:
Elencar como deve ser o movimento da bola;

## Requisitos:
- RF1: Movimentar a bola;
- RF2: Verificar colisão com bordas ou raquetes;
- RF3: Verificar se foi feito gol;

## Atores:
- Bola;

## Prioridade:
Não se Aplica

## Pré-Condições:
- Verifica se vai se o jogo está iniciado;

## Frequência de Uso:
Não se aplica;

## Criticidade:
Não se Aplica

## Fluxo Principal:

### Inicialização:
- Começa a se movimentar para um dos lados, com angulo aleatório.

### Loop do Jogo:
- Verifica se jogo está pausado;
- Verifica posição anterior e angulo;
- Verifica se colidiu com parede, raquete ou gol
    - Se colidir com parede, trocar direção com mesmo angulo
    - Se colidir com raquete, ir na direção contrária e calcular angulo de acordo com parte da raquete batida.
    - Se colidiu com gol, adicionar ponto ao jogador do lado oposto;
- Movimentar para próximo ponto.

### Finalização:
- Se for gol, voltar para parte centro e iniciar fazer inicialização de novo.

## Fluxo Alternativo:
Não se aplica

### Pós Condições:
Não se aplica

## Regras de Negócio
- Deve de forma aleatória escolher um lado para começar, e um angulo aleatório;
- Ao bater na parede deve mudar o lado com mesmo angulo de batida;
- Ao bater na raquete, verificar local onde bateu e calcular novo angulo e voltar para lado oposto;
- Ao bater no gol, dar ponto e reiniciar trazer nova inicialização, de forma aleatório tanto o lado quanto o angulo inicial;