/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 18;
const int BTN_PIN = 19;

const int MARCA1_PIN = 13;
const int MARCA2_PIN = 12;
const int MARCA3_PIN = 11;
const int MARCA4_PIN = 10;

int main() {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(MARCA1_PIN);
    gpio_set_dir(MARCA1_PIN, GPIO_OUT);
    gpio_init(MARCA2_PIN);
    gpio_set_dir(MARCA2_PIN, GPIO_OUT);
    gpio_init(MARCA3_PIN);
    gpio_set_dir(MARCA3_PIN, GPIO_OUT);
    gpio_init(MARCA4_PIN);
    gpio_set_dir(MARCA4_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    while (true) {
        if (!gpio_get(BTN_PIN)) {
            gpio_put(LED_PIN, 1);
            sleep_ms(500);
            gpio_put(LED_PIN, 0);
            while (!gpio_get(BTN_PIN)) {
            };
        }

        gpio_put(MARCA1_PIN, 1);
        sleep_ms(50);
        gpio_put(MARCA1_PIN, 0);
        gpio_put(MARCA2_PIN, 1);
        sleep_ms(50);
        gpio_put(MARCA2_PIN, 0);
        gpio_put(MARCA3_PIN, 1);
        sleep_ms(50);
        gpio_put(MARCA3_PIN, 0);
        gpio_put(MARCA4_PIN, 1);
        sleep_ms(50);
        gpio_put(MARCA4_PIN, 0);
    }
}
