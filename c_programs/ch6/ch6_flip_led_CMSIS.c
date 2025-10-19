/* Same as ch2, but using the CMSIS headers */

#include "stm32f4xx.h"

// Bit mask for enabling GPIOA (bit 0)
#define GPIOAEN (1U<<0)
// Bit mask for GPIOA pin 5
#define PIN5 (1U<<5)
// Alias for PIN5 representing LED pin
#define LED_PIN PIN5

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
        for(int i=0; i<100000; i++){}
        GPIOA->ODR ^= LED_PIN;
        for(int i=0; i<500000; i++){}
    }
}
