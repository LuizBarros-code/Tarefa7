# Projeto de Exibição com Display OLED e Matriz de LEDs

Este projeto utiliza um display OLED SSD1306 e uma matriz de LEDs 5x5 para exibir informações e padrões visuais. O código foi desenvolvido para rodar em um microcontrolador Raspberry Pi Pico, utilizando a linguagem C e as bibliotecas do SDK do Pico.

## Componentes Principais

### Display OLED SSD1306
- **Inicialização**: Configuração do display via I2C, definição de largura, altura e endereço.
- **Funções**:
  - `display_init`: Inicializa o display e configura os pinos I2C.
  - `display_draw`: Desenha strings no display em posições específicas.
  - `ssd1306_draw_char`: Desenha caracteres individuais no display.
  - `ssd1306_draw_string`: Desenha strings completas no display.
  - `ssd1306_fill`: Preenche o display com um valor específico (ligado ou desligado).

### Matriz de LEDs 5x5
- **Inicialização**: Configuração dos LEDs WS2812B via PIO (Programmable I/O) do Raspberry Pi Pico.
- **Funções**:
  - `inicializar_leds`: Configura os pinos e inicializa a matriz de LEDs.
  - `definir_led`: Define a cor e intensidade de um LED específico.
  - `escrever_leds`: Envia os dados para a matriz de LEDs.
  - `limpar_leds`: Desliga todos os LEDs.
  - `exibir_numero`: Exibe um número na matriz de LEDs usando padrões pré-definidos.

### Botões e LEDs
- **Botões**: Dois botões são utilizados para alternar o estado de LEDs verde e azul.
- **LEDs**: LEDs verde e azul são controlados pelos botões, com estados alternados a cada pressionamento.

## Funcionalidades
- **Exibição de Texto**: O display OLED pode exibir strings e caracteres individuais.
- **Exibição de Números**: A matriz de LEDs exibe números de 0 a 9 usando padrões pré-definidos.
- **Controle de LEDs**: Os botões permitem alternar o estado dos LEDs verde e azul, com feedback visual no display OLED.

## Estrutura do Código
- **display.h**: Contém as definições e protótipos das funções relacionadas ao display OLED.
- **font.h**: Contém a definição da fonte utilizada para exibir caracteres no display.
- **matriz.h**: Contém as definições e protótipos das funções relacionadas à matriz de LEDs.
- **main.c**: Contém a lógica principal do programa, incluindo a inicialização dos componentes e o loop principal.

## Como Usar
1. Conecte o display OLED e a matriz de LEDs ao Raspberry Pi Pico conforme as definições de pinos no código.
2. Compile e carregue o código no Pico.
3. Utilize os botões para alternar o estado dos LEDs e observe a exibição no display OLED e na matriz de LEDs.

## Vídeo Demonstrativo
Assista ao vídeo demonstrativo deste projeto no YouTube: [https://youtu.be/P_jkKU5OSe8]