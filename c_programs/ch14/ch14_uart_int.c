#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "gpio_exti.h"
#include "gpio_led.h"

int main(void){
    /* Initialise debug UART, LED and Button */
    uart_init();
    init_led();

    /* Initialise EXT1 */
    pc13_exti_init();

    while(1){}
}

static void exti_callback(void){
    printf("BTN Pressed...\n\r");
    toggle_led();
}

/* We have set a weak link in the startup assembly script. This function overrides that call. */
void EXTI15_10_IRQHandler(void){
    if((EXTI->PR & LINE13) != 0){
        /* Clear the PR flag */
        EXTI->PR |= LINE13;

        //Do something
        exti_callback();
    }
}
