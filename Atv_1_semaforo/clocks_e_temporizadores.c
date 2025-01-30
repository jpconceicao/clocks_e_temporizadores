#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

#define RED_LED_PIN 18
#define YELLOW_LED_PIN 19
#define GREEN_LED_PIN 20

#define RED_RGB 13
#define GREEN_RGB 11
#define BLUE_RGB 12  // Pino Amarelo para o wokwi

typedef enum {
    VERMELHO,
    VERDE,
    AMARELO
} estado_t;

estado_t estado_atual = VERMELHO;

bool funcaro_de_repeticao_callback();
void setup_gpios();

int main()
{
    stdio_init_all();
    setup_gpios();

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, funcaro_de_repeticao_callback, NULL, &timer);

    

    while (true) {
        sleep_ms(9000);
         printf("Repetição\n");
    }
}

bool funcaro_de_repeticao_callback(struct repeating_timer *t)
{
    printf("3 segundos passou");
    // Alternar entre os estados do semáforo
    switch (estado_atual) {
        case VERMELHO:
            // LEDs normais
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 1);

            // LED RGB
            gpio_put(GREEN_RGB, 1);
            gpio_put(BLUE_RGB, 0);
            gpio_put(RED_RGB, 0);

            estado_atual = VERDE;
            break;
        case VERDE:
            // LEDs normais
            gpio_put(RED_LED_PIN, 0);
            gpio_put(YELLOW_LED_PIN, 1);
            gpio_put(GREEN_LED_PIN, 0);

            // LED RGB
            gpio_put(GREEN_RGB, 1);
            gpio_put(BLUE_RGB, 0);
            gpio_put(RED_RGB, 1);

            estado_atual = AMARELO;
            break;
        case AMARELO:
            // LEDs normais
            gpio_put(RED_LED_PIN, 1);
            gpio_put(YELLOW_LED_PIN, 0);
            gpio_put(GREEN_LED_PIN, 0);

            // LED RGB
            gpio_put(GREEN_RGB, 0);
            gpio_put(BLUE_RGB, 0);
            gpio_put(RED_RGB, 1);

            estado_atual = VERMELHO;
            break;
        default:
            break;
    }
    return true; // Retornando `true` mantém o timer ativo
}

void setup_gpios()
{
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_init(YELLOW_LED_PIN);
    gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(RED_RGB);
    gpio_set_dir(RED_RGB, GPIO_OUT);
    gpio_init(GREEN_RGB);
    gpio_set_dir(GREEN_RGB, GPIO_OUT);
    gpio_init(BLUE_RGB);
    gpio_set_dir(BLUE_RGB, GPIO_OUT);

    gpio_put(RED_LED_PIN, 1);
    gpio_put(YELLOW_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(RED_RGB, 1);
    gpio_put(BLUE_RGB, 0);
    gpio_put(GREEN_RGB, 0);
}
