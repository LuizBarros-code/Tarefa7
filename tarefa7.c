#include "inc/font.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "inc/display.h"
#include "inc/matriz.h" 

#define TEMPO_DEBOUNCE 150
#define PINO_BOTAO_A 5
#define PINO_BOTAO_B 6
#define LED_GREEN 11
#define LED_BLUE 12

// Declarações das variáveis globais
bool buttonA_last_state = true;
bool buttonB_last_state = true;
bool led_green_state = false;
bool led_blue_state = false;

bool debounce(uint32_t *ultimo_tempo, uint32_t tempo_debounce);

ssd1306_t ssd;

uint32_t last_button_A = 0;
uint32_t last_button_B = 0;

void gpio_callback(uint gpio, uint32_t events) {
    if (gpio == PINO_BOTAO_A && debounce(&last_button_A, TEMPO_DEBOUNCE)) {
        led_green_state = !led_green_state;
        if (led_green_state) {
            led_blue_state = false;
        }
        printf("Botão A pressionado\n");
        atualizar_leds(led_green_state, led_blue_state);
        printf("LED Verde %s\n", led_green_state ? "Ligado" : "Desligado");
        display_draw(&ssd, "LED Verde", led_green_state ? "Ligado" : "Desligado");
    } else if (gpio == PINO_BOTAO_B && debounce(&last_button_B, TEMPO_DEBOUNCE)) {
        led_blue_state = !led_blue_state; // Alterna o estado do LED azul
        if (led_blue_state) {
            led_green_state = false;
        }
        printf("Botão B pressionado\n");
        atualizar_leds(led_green_state, led_blue_state);
        printf("LED Azul %s\n", led_blue_state ? "Ligado" : "Desligado");
        display_draw(&ssd, "LED Azul", led_blue_state ? "Ligado" : "Desligado");
    }
}

void atualizar_leds(bool led_green_state, bool led_blue_state) {
    gpio_put(LED_GREEN, led_green_state);
    gpio_put(LED_BLUE, led_blue_state);
}

bool debounce(uint32_t *ultimo_tempo, uint32_t tempo_debounce) {
    uint32_t agora = to_ms_since_boot(get_absolute_time());
    if (agora - *ultimo_tempo >= tempo_debounce) {
        *ultimo_tempo = agora;
        return true;
    }
    return false;
}

int main() {
    stdio_init_all();

    display_init(&ssd);
    inicializar_leds(PINO_LED);

    limpar_leds();

    gpio_init(PINO_BOTAO_A);
    gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_A);
    gpio_set_irq_enabled_with_callback(PINO_BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(PINO_BOTAO_B);
    gpio_set_dir(PINO_BOTAO_B, GPIO_IN);
    gpio_pull_up(PINO_BOTAO_B);
    gpio_set_irq_enabled_with_callback(PINO_BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    while(1){
        int ch = getchar_timeout_us(0);
        if(ch != PICO_ERROR_TIMEOUT){
            char c = (char)ch;
            char text[2] = {c, '\0'};
            if (time_us_64() - last_button_A > TEMPO_DEBOUNCE && time_us_64() - last_button_B > TEMPO_DEBOUNCE){
                display_draw(&ssd, "caractere:", text);
                printf("Caractere: %c\n", c);

                if(c >= '0' && c <= '9'){
                    int numero = c - '0';
                    exibir_numero(numero);
                }
            }
        }
    }
}