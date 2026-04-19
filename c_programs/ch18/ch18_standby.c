#include <stdio.h>
#include <string.h>
#include "standby_mode.h"
#include "gpio_exti.h"
#include "uart.h"


static void check_reset_source(void);


/* The code uses the user button to trigger standby mode. Then it relies on the rising edge on 
   the WKUP pin (PA0) to wake up the baord. I am using a breadboard to make a simple wakeup button:
   
   3.3V ─────┐
             │
              /  Switch
             o
             │
             ┼────────┐
             │        │
           ┌─┴─┐  ┌───┴───┐
           │ 10│  │  WKUP │
           │ K │  │  PA0  │
           │ Ω │  └───────┘
           └─┬─┘
             ▼ 
            GND
   */
int main(void){
    uart_init();

    wakeup_pin_init();

    /* Find reset source */
    check_reset_source();

    /* Initialise EXTI so that pressing the user button triggers
       an interrupt and get the board into standby mode */
    pc13_exti_init();;

    while(1){
        printf("I am awake!!\r\n");
        for (int i=0; i< 1000000; i++){}
    }
}

/* Check why we are resetting - is it a fresh start or are we
   waking up from the standby mode?
   */
static void check_reset_source(void){
    /* Enable clock access to PWR */
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;

    /* Have we woken up from standby mode? */
    if ((PWR->CSR & PWR_CSR_SBF) == (PWR_CSR_SBF)){
        /* Clear Standby flag */
        PWR->CR |= PWR_CR_CSBF;

        printf("System resume from standby.. \r\n");

        /* Wait for wakeup pin to be released */
        while(get_wakeup_pin_state() == 0){}
    } else {
        printf("Just waking up fresh.. \r\n");
    }

    /* Check and clear wakeup flag */
    if((PWR->CSR & PWR_CSR_WUF) == PWR_CSR_WUF){
        PWR->CR |= PWR_CR_CWUF;
    }
}

static void exti_callback(){
    standby_wakeup_pin_setup();
}

void EXTI15_10_IRQHandler(void){
    if((EXTI->PR & LINE13) != 0){
        /* Clear PR flag */
        EXTI->PR |= LINE13;

        // Do something...
        exti_callback();
    }
}
