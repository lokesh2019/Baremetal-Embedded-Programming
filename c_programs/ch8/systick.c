#include "systick.h"

#define CTRL_ENABLE              (1U<<0)
#define CTRL_CLCKSRC             (1U<<2)
#define CTRL_COUNTFLAG           (1U<<16)

/* By default, the frequency of the MCU is 16MHz. 16M per 1s, 16K per 1ms */
#define ONE_MSEC_LOAD  16000 

void systick_msec_delay(uint32_t delay) {
    /* Load number of clock cycles per millisecond */
    SysTick->LOAD = ONE_MSEC_LOAD - 1;

    /* Clear systick current value register*/
    SysTick->VAL = 0;

    /* Select internal clock source */
    SysTick->CTRL = CTRL_CLCKSRC;

    /* Enable systick */
    SysTick->CTRL |= CTRL_ENABLE;

    for (int i=0; i<delay; i++){
        /* Wait for the timer to get hit 0, that is 1ms. Loop for "delay" ms */
        while((SysTick-> CTRL & CTRL_COUNTFLAG) == 0){}
    }

    /* Finally, disable systick */
    SysTick->CTRL = 0;
}
