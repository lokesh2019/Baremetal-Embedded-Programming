#include "gpio.h"
#include "systick.h"

int main(void){
    /* Initialise GPIO port A */
    init_led();
    /* Flip SHORT_LONG_SHORT sequence with 1000ms - 3000ms - 1000ms duration. Interval is 1000ms. */
    while (1)
    {
        led_toggle(); /* ON-SHORT*/
        systick_msec_delay(1000);
        led_toggle(); /* OFF */
        systick_msec_delay(1000);
        led_toggle(); /* ON-LONG */
        systick_msec_delay(3000);
        led_toggle(); /* OFF */
        systick_msec_delay(1000);
        led_toggle(); /* ON-SHORT*/
        systick_msec_delay(1000);
        led_toggle(); /* OFF */
        systick_msec_delay(1000);
    }
}
