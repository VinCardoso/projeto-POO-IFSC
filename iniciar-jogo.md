# Caso de Uso: Iniciar e Controlar Pontuação Jogo

## Objetivo:
Descrever a lógica de início do jogo de pong e fazer o controle de pontos;

## Requisitos:
- RF1: Identificar quantos jogadores vão jogar;
- RF2: Posicionar elementos nos locais iniciais;
- RF3: Mensurar Placar;

## Atores:
- Jogador 1
- Jogador 2

## Prioridade:
Não se Aplica

## Pré-Condições:
- Verifica se vai ser 1 ou 2 jogadores;
- As raquetes e a bola devem estar posicionadas na posição inicial;
- O placar para os dois lados com 0;

## Frequência de Uso:
1 vez a cada Partidada

## Criticidade:
Não se Aplica

## Fluxo Principal:

### Inicialização:
- Seleciona 1 ou 2 jogadores;
- Instancia dois objetos raquetes e o objeto bola.
- Coloca os elementos nas posições iniciais.
- Zera o placar
- Começa o loop do jogo;

### Loop do Jogo:
- Fica verificando se algum dos lados fez 5 pontos para finalizar o jogo.

### Finalização:
- Se um dos lados tiver feito 5 pontos aparece na tela “Player X Venceu! Pressione 'R' para Reiniciar.”, e ao apertar R reinicia o jogo.

## Fluxo Alternativo:

## Pausar:
- Ao apertar P pausa a bola no local original com informações de para onde a bola está indo e os botões de movimentar raquetes param de fazer função.
- Aparece alerta na tela escrito “Jogo Pausado - Aperte P para Continuar”

## Continuar:
- Ao apertar P de novo volta o jogo e a bola continua com a mesma velocidade e direção e é liberado para continuar podendo mover as raquetes.

### Pós Condições:
Após a partirda finalizar o jogo fica parado até apertar R para jogar novamente.

## Regras de Negócio
- Ao selecionar 1 jogador ter apenas 1 controle de raquetes que vão se mexer ao mesmo tempo;
- A partida é vencida ao alcançar 5 pontos;
- Ao pressionar P o jogo pausa, e apertar P de novo ele continua da onde parou;
- Ao apertar R o jogo reinicia;