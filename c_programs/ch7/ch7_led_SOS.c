/* Same as ch2, but using the CMSIS headers */

#include "gpio.h"

int main(void){
    /* Initialise GPIO port A */
    init_gpioA();
    /* Flip LED every 10k iterations */
    while (1)
    {
        /* Blink S-O-S */
        short_flash();
        short_flash();
        short_flash();
        long_flash();
        long_flash();
        long_flash();
        short_flash();
        short_flash();
        short_flash();
        pause();
    }
}
