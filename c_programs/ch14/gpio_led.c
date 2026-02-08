#include "stm32f4xx.h"
#include "gpio_led.h"
#include "stdbool.h"

void init_led(void) {
    /* Enable clock access to GPIOA and GPIOC*/
    RCC->AHB1ENR |= GPIOAEN;
    /* Set GPIO-A pin-5 mode to output */
    GPIOA->MODER |= (1U<<10); // Set bit 10 to 1
    GPIOA->MODER &= ~(1U<<11); // Set bit 11 to 0
}

void toggle_led(void) {
    GPIOA->ODR ^= LED_PIN;
}
