#include <stdio.h>
#include "gpio_led.h"
#include "gpio_exti.h"
#include "iwdg.h"
#include "uart.h"

uint8_t g_button_press;
static void check_reset_source(void);

/****
Program description:
- Blue button on the board is connected to the LED to trigger interrupts
- On first boot, reset was not done by the IWDG, so program enters while loop and LED blinks normally
- Watchdog gets reset on time
And then..
- User presses the button, triggering an interrupt
- Interrupt handler function stops the main loop from resetting watchdog
- Watchdog resets the main processor
- Main processor re-enters main() function, detects the reset was caused by the IWDG
- Main function waits here until user presses the button again to get out of check_reset_source function
- Program enters "normal" mode of blinking LED

*****/

int main(void){
    /* Initialise debug uart */
    uart_init();

    /* Initialise LED */
    led_init();

    /* Initialise EXTI */
    pc13_exti_init();

    /* Find reset source */
    check_reset_source();

    /* Initialise IWDG */
    iwdg_init();

    while(1){
        if(g_button_press != 1){
            /* Refresh IWDG down-counter to default value */
            IWDG->KR = IWDG_KEY_RELOAD;
            led_toggle();
            for(int i=0;i<90000;i++){}
        }
    }
}

static void check_reset_source(void) {
    if ((RCC->CSR & RCC_CSR_IWDGRSTF) == (RCC_CSR_IWDGRSTF)){
        /* Clear IWDG reest flag */
        RCC->CSR = RCC_CSR_RMVF;

        /* Turn LED on */
        led_on();
        printf("Reset was caused by IWDG...\n\r");

        while(g_button_press != 1){}
        g_button_press = 0;
    }
}

static void exti_callback(void){
    g_button_press = 1;
}

void EXTI15_10_IRQHandler(void){
    if((EXTI->PR & LINE13) != 0){
        /* Clear the PR flag */
        EXTI->PR |= LINE13;
        /* Do something */
        exti_callback();
    }
}
