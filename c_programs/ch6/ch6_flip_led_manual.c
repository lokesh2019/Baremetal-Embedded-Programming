/* Same as ch2, but using the gpio struct typedefs */

#include "register_definitions.h"

int main(void){
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;
    /* Set GPIO pin-5 mode to output */
    GPIOA->MODER |= (1U<<10); // Set bit 10 to 1
    GPIOA->MODER &= ~(1U<<11); // Set bit 11 to 0

    /* Flip LED every 10k iterations */
    while (1)
    {
        GPIOA->ODR ^= LED_PIN;
        for(int i=0; i<5000000; i++){}
    }
}
