#include <stdio.h>
#include "pico/stdio.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

#define BOTAO_A     5
#define RED_RGB     13
#define GREEN_RGB   11
#define BLUE_RGB    12

typedef enum {
    TUDO_OFF,
    TRES_LIGADOS,
    DOIS_LIGADOS,
    UM_LIGADO
} estado_t;

estado_t estado_atual = TUDO_OFF;

bool leds_ativos = false;

void setup_gpios();
int64_t alarm_callback(alarm_id_t id, void *user_data);

int main()
{
    stdio_init_all();
    setup_gpios();

    while (true) {
        if (gpio_get(BOTAO_A) == 0 && !leds_ativos)
        {
            sleep_ms(50);
            if (gpio_get(BOTAO_A) == 0)
            {
                printf("Entrou na ativacao");
                leds_ativos = true;
                estado_atual = TRES_LIGADOS;

                gpio_put(RED_RGB, 1);
                gpio_put(BLUE_RGB, 1);
                gpio_put(GREEN_RGB, 1);

                add_alarm_in_ms(3000, alarm_callback, NULL, false);
            }
        }
    }
}

void setup_gpios()
{
    gpio_init(RED_RGB);
    gpio_set_dir(RED_RGB, GPIO_OUT);
    gpio_init(GREEN_RGB);
    gpio_set_dir(GREEN_RGB, GPIO_OUT);
    gpio_init(BLUE_RGB);
    gpio_set_dir(BLUE_RGB, GPIO_OUT);

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_put(RED_RGB, 0);
    gpio_put(BLUE_RGB, 0);
    gpio_put(GREEN_RGB, 0);
}

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("Entrou na timer");
    switch (estado_atual) {
        case TRES_LIGADOS:
            gpio_put(RED_RGB, 0);
            estado_atual = DOIS_LIGADOS;
            add_alarm_in_ms(3000, alarm_callback, NULL, false);
            break;
        case DOIS_LIGADOS:
            gpio_put(GREEN_RGB, 0);
            estado_atual = UM_LIGADO;
            add_alarm_in_ms(3000, alarm_callback, NULL, false);
            break;
        case UM_LIGADO:
            gpio_put(BLUE_RGB, 0);
            estado_atual = TUDO_OFF;
            leds_ativos = false;
            break;
        default:
            break;
    }

    return 0;
}
