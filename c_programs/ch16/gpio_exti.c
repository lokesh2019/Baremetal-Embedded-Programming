#include "gpio_exti.h"

#define GPIOCEN (1U<<2)
#define SYSCFGEN (1U<<14)

static void init_button(void) {
    /* Enable clock access to GPIOA and GPIOC*/
    RCC->AHB1ENR |= GPIOCEN;
    /* Set GPIO-C pin-13 mode to input */
    GPIOC->MODER &= ~(1U<<26); // Set bit 26 to 0
    GPIOC->MODER &= ~(1U<<27); // Set bit 27 to 0
}

void pc13_exti_init(void){
    /* We use the button to trigger interrupts on EXTI13 line. */
    init_button();

    /* Board support package function. Disable global interrupts */
    __disable_irq();

    /* Enable clock access to SYSCFG */
    RCC->APB2ENR |= SYSCFGEN;

    /* Select PORTC for EXTI13. Set SYSCFG_EXTICR4 EXTI13 to 0010 (i.e. map PC13 line to EXTI13) */
    SYSCFG->EXTICR[3] |= (1U<<5);

    /* Unmask EXTI13*/
    EXTI->IMR |= (1U<<13);

    /* Select falling edge trigger */
    EXTI->FTSR |= (1U<<13);

    /* Board support package function. Enable EXTI13 line in NVIC. See RM0383, page 204. There is just one value to enable EXT Interuppt lines 10-15. */
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    /* Board support package function. Enable global interrupts */
    __enable_irq();
}
