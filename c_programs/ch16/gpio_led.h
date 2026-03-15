#include "stdbool.h"

// Bit mask for enabling GPIOA (bit 0)
#define GPIOAEN (1U<<0)

// Alias for PIN5 representing LED pin
#define LED_PIN (1U<<5)

// Set and reset  LED (pin 5) with BSRR
#define SET_PIN5_BSRR (1U<<5)
#define RESET_PIN5_BSRR (1U<<21)

extern void led_init(void);
extern void led_toggle(void);
extern void led_on(void);
extern void led_off(void);
