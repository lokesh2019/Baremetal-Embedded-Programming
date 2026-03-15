#include "stm32f4xx.h"
#include "gpio_led.h"
#include "stdbool.h"

void led_init(void) {
    /* Enable clock access to GPIOA and GPIOC*/
    RCC->AHB1ENR |= GPIOAEN;
    /* Set GPIO-A pin-5 mode to output */
    GPIOA->MODER |= (1U<<10); // Set bit 10 to 1
    GPIOA->MODER &= ~(1U<<11); // Set bit 11 to 0
}

void led_toggle(void) {
    GPIOA->ODR ^= LED_PIN;
}

void led_on(void){
    GPIOA->ODR |= LED_PIN;
}

void led_off(void){
    GPIOA->ODR &= ~LED_PIN;
}
