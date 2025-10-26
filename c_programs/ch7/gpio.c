#include "stm32f4xx.h"
#include "gpio.h"
#include "stdbool.h"

void init_led() {
    /* Enable clock access to GPIOA and GPIOC*/
    RCC->AHB1ENR |= GPIOAEN;
    /* Set GPIO-A pin-5 mode to output */
    GPIOA->MODER |= (1U<<10); // Set bit 10 to 1
    GPIOA->MODER &= ~(1U<<11); // Set bit 11 to 0
}

void init_button() {
    /* Enable clock access to GPIOA and GPIOC*/
    RCC->AHB1ENR |= GPIOCEN;
    /* Set GPIO-C pin-13 mode to input */
    GPIOC->MODER &= ~(1U<<26); // Set bit 26 to 0
    GPIOC->MODER &= ~(1U<<27); // Set bit 27 to 0
}

void set_led() {
    GPIOA->BSRR |= SET_PIN5_BSRR;
}

void reset_led() {
    GPIOA->BSRR |= RESET_PIN5_BSRR;
}

void short_flash() {
    set_led();
    for(int i=0; i<500000; i++){}
    reset_led();
    for(int i=0; i<500000; i++){}
}

void long_flash() {
    set_led();
    for(int i=0; i<2000000; i++){}
    reset_led();
    for(int i=0; i<500000; i++){}
}

void pause() {
    for(int i=0; i<3000000; i++){}
}

bool button_pressed() {
    /* Button is ACTIVE LOW. Discovered by writing wrong state first */
    return (GPIOC->IDR &= 1U<<13) == 0;
}
