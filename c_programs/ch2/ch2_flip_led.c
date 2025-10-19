#include "register_definitions.h"

int main(void){
    /* Enable clock access to GPIOA */
    RCC_AHB1EN_R |= GPIOAEN;
    /* Set GPIO pin-5 mode to output */
    GPIOA_MODE_R |= (1U<<10); // Set bit 10 to 1
    GPIOA_MODE_R &= ~(1U<<11); // Set bit 11 to 0

    /* Flip LED every 10k iterations */
    while (1)
    {
        GPIOA_OD_R ^= LED_PIN;
        for(int i=0; i<5000000; i++){}
    }
}
