#include "gpio.h"
#include "tim.h"

int main(void){
    /* Initialise GPIO port A */
    init_led();
    tim2_1hz_init();
    /* Flip SHORT_LONG_SHORT sequence with 1000ms - 3000ms - 1000ms duration. Interval is 1000ms. */
    while (1)
    {   
        led_toggle();
        /* Wait for UIF */
        while(!(TIM2->SR & SR_UIF)) {}
        /* Clear UIF */
        TIM2->SR &=~SR_UIF;
    }

}
