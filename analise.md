# Análise orientada a objeto
> [!NOTE]
> A **análise** orientada a objeto consiste na descrição do problema a ser tratado, duas primeiras etapas da tabela abaixo, a definição de casos de uso e a definição do domínio do problema.

## Descrição Geral do domínio do problema

O projeto trata do desenvolvimento do clássico jogo eletrônico Pong.

O sistema consiste em uma partida onde um ou dois jogadores controlam raquetes verticais, posicionadas nas extremidades da tela.

O objetivo principal é rebater uma bola, impedindo que ela ultrapasse sua raquete, ao mesmo tempo em que se tenta fazer com que a bola ultrapasse a raquete do oponente para marcar pontos.

A partida se encerra quando um dos jogadores atinge uma pontuação pré-determinada de 5 pontos.

## Diagrama de Casos de Uso

[**Caso de Uso: Iniciar e Controlar Pontuação Jogo**](iniciar-jogo.md)<br>
[**Caso de Uso: Mover Bola**](movimentacao-bola.md)<br>
[**Caso de Uso: Mover Raquete**](movimentacao-raquetes.md)
 
## Diagrama de Domínio do problema

- **Partida**: Controla as regras, colisões entre bola e sabe o que está acontecendo;
- **Tela**: A interface do jogo e que interpretas as ações do jogador;
- **Jogador**: É o ator que controla as raquetes, podendo ter um ou dois jogadores;
- **Raquete**: Objeto que fica nas extremidades da tela com tamanho definido e que pode se movimentar para cima e pra baixo para "defender" a entrada da bola;
- **Bola**: Objeto que reage ao enconstar com as raquetes indo para o lado oposto, ou para cima ou para baixo quanto bate nas paredes inferior e superior, e quando bate no gol marca ponto para o jogador do lado adversário;
- **Parede**: Extremidade superior e inferior que limita a saída da bola;
- **Gol**: Parede atrás das raquetes;


<div align="center">

[Retroceder](README.md) | [Avançar](projeto.md)

</div>