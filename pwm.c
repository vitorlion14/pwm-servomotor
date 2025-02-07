#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Define os pinos do servomotor e do LED
#define SERVO_PIN 22
#define LED_PIN 12  // Pino para o LED

void setup_pwm(uint gpio, float clkdiv, uint16_t wrap) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Configura o pino para função PWM
    gpio_set_function(gpio, GPIO_FUNC_PWM);

    // Define o divisor de clock para o PWM
    pwm_set_clkdiv(slice_num, clkdiv);

    // Configura o valor máximo do contador (período do PWM)
    pwm_set_wrap(slice_num, wrap);

    // Inicializa o PWM com nível baixo
    pwm_set_gpio_level(gpio, 0);
    pwm_set_enabled(slice_num, true);
}

void set_servo_position(uint gpio, uint32_t pulse_width_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    uint32_t level = (pulse_width_us * 20000) / 20000;  // Calcula o duty cycle
    pwm_set_gpio_level(gpio, level);
}

void set_led_brightness(uint gpio, uint8_t brightness) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_gpio_level(gpio, brightness * 65535 / 255);  // Ajusta o nível do LED
}

void smooth_servo_movement(uint gpio, uint32_t start_pulse, uint32_t end_pulse) {
    if (start_pulse < end_pulse) {
        for (uint32_t pulse = start_pulse; pulse <= end_pulse; pulse += 5) {
            set_servo_position(gpio, pulse);

            // Ajusta o brilho do LED conforme o movimento do servo
            uint8_t brightness = (pulse - 500) * 255 / (2400 - 500);
            set_led_brightness(LED_PIN, brightness);

            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }
    } else {
        for (uint32_t pulse = start_pulse; pulse >= end_pulse; pulse -= 5) {
            set_servo_position(gpio, pulse);

            // Ajusta o brilho do LED conforme o movimento do servo
            uint8_t brightness = (pulse - 500) * 255 / (2400 - 500);
            set_led_brightness(LED_PIN, brightness);

            sleep_ms(10);  // Atraso de 10ms para suavizar o movimento
        }
    }
}

int main() {
    // Inicializa o PWM para o servomotor e o LED
    setup_pwm(SERVO_PIN, 125.0, 20000);  // Servo com 50Hz (20ms)
    setup_pwm(LED_PIN, 64.0, 65535);  // LED

    // Ajusta a flange do servomotor para a posição de 180 graus (2400µs) e aguarda 5 segundos
    set_servo_position(SERVO_PIN, 2400);
    sleep_ms(5000);

    // Ajusta a flange do servomotor para a posição de 90 graus (1470µs) e aguarda 5 segundos
    set_servo_position(SERVO_PIN, 1470);
    sleep_ms(5000);

    // Ajusta a flange do servomotor para a posição de 0 graus (500µs) e aguarda 5 segundos
    set_servo_position(SERVO_PIN, 500);
    sleep_ms(5000);

    // Movimentação periódica suave do servo e ajuste do brilho do LED
    while (1) {
        smooth_servo_movement(SERVO_PIN, 500, 2400);  // Movimento suave de 0 a 180 graus
        sleep_ms(500);

        smooth_servo_movement(SERVO_PIN, 2400, 500);  // Movimento suave de 180 a 0 graus
        sleep_ms(500);
    }

    return 0;
}
