/* Same as ch2, but using the CMSIS headers */

#include "gpio.h"

int main(void){
    init_led();
    init_button();
    /* Flip LED every 10k iterations */
    while (1)
    {
        if (button_pressed()){
            set_led();
        } else {
            reset_led();
        }
    }
}
