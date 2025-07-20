# Implementação

## Ferramentas e Bibliotecas
O projeto foi desenvolvido em C++ utilizando o Qt Creator.

### Bibliotecas utilizadas:

- Módulo Qt Widgets: Para a criação da janela principal e de todos os elementos de interface, como botões e rótulos de texto.

- Módulo Qt GUI: Para a renderização 2D customizada através do QPainter, que foi essencial para desenhar todos os objetos do jogo (bola, raquetes, paredes).

- Módulo Qt Core: Para a estrutura fundamental da aplicação, o sistema de sinais e slots (signals e slots) para a comunicação entre objetos, e o loop de eventos com QTimer para controlar a animação e a lógica do jogo.

### Arquitetura do Projeto
A implementação seguiu o princípio da Separação de Preocupações, dividindo o projeto em duas classes centrais:

qtGraphics: Responsável exclusivamente pela parte visual e de interação com o usuário (desenhar na tela, capturar teclas, mostrar menus e placar).

MyScene: Responsável por toda a lógica do jogo (regras, movimentação dos objetos, detecção de colisão, contagem de pontos), funcionando como o motor do jogo.

Essa separação tornou o código mais organizado.

## Desafios e Soluções no Desenvolvimento
Durante a implementação, vários desafios surgiram. A seguir, descrevo os principais problemas e as soluções aplicadas.

1. Colisão que "grudava" a Bola
- Problema: Após uma colisão, a bola frequentemente ficava presa na superfície de um objeto (raquete ou parede), resultando em múltiplas detecções de colisão em frames consecutivos e um comportamento de ficar tremendo e não sair mais lá.

- Solução: A solução foi ajustar manualmente a posição da bola para fora da área de colisão do objeto imediatamente após a detecção do impacto. Por exemplo, ao colidir com a raquete do jogador 1, a posição X da bola era corrigida para a borda direita da raquete, impedindo que ela ficasse sobreposta no frame seguinte.

2. Dinamismo na Saída da Bola
- Problema: Para tornar o início de cada ponto menos previsível, implementei um ângulo de saque aleatório. No entanto, ângulos muito próximos de 90° (muito verticais) faziam a bola demorar excessivamente para alcançar as raquetes, deixando o jogo lento e monótono.

- Solução: Foi implementado um laço do-while que gera um novo ângulo aleatório caso o ângulo sorteado seja muito vertical. A verificação qAbs(qCos(angle)) < 0.2 garante que o componente horizontal da velocidade seja sempre significativo, mantendo o jogo dinâmico.

3. Rebatida Dinâmica na Raquete
- Problema: A implementação inicial da colisão com a raquete apenas invertia a direção horizontal da bola. Isso tornava o jogo muito previsível, pois o ângulo de retorno era sempre o mesmo.

- Solução: O sistema de colisão foi aprimorado para calcular o ponto exato onde a bola atinge a raquete. Com base nesse ponto de impacto (mais perto do topo, no centro ou mais perto da base), um novo ângulo de reflexão é calculado. Isso permite que o jogador tenha controle sobre a direção da bola, tornando o jogo muito mais dinâmico.

4. Limites de Movimento da Raquete
- Problema: No início, houve uma dificuldade em entender o sistema de coordenadas do QPainter para impedir que as raquetes ultrapassassem os limites superior e inferior da área de jogo.

- Solução: Após compreender que a posição (0,0) de um objeto é seu canto superior esquerdo, a lógica de movimento foi ajustada. Utilizando std::max() e std::min(), o movimento da raquete é travado, garantindo que sua posição Y nunca seja menor que o limite mínimo (p_minY) nem maior que o limite máximo (p_maxY).

5. Centralização de Constantes
- Oportunidade para melhorar o código: Muitos valores importantes (como tamanho da tela, velocidade da bola, etc.) estavam espalhados por diversas classes. 

- Solução: Foi criado um arquivo de cabeçalho central, constants.h, contendo todas as constantes globais do jogo. Isso centralizou a configuração do jogo em um único local, facilitando ajustes e a manutenção do código.

6. Mecanismo de Reset para Testes
- Problema: Testar pequenas mudanças na física ou na lógica do jogo era ineficiente, pois exigia jogar um ponto inteiro ou reiniciar a aplicação.

- Solução: Implementei uma funcionalidade para reiniciar o jogo pressionando a tecla 'R'. O método resetGame() da MyScene foi criado para reposicionar a bola e as raquetes e zerar o placar. Essa funcionalidade se mostrou útil que mantive na versão final como a maneira de "Jogar Novamente" após o fim de uma partida.

<div align="center">

[Retroceder](projeto.md) | [Início](analise.md)

</div>