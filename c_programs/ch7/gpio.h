#include "stdbool.h"

// Bit mask for enabling GPIOA (bit 0)
#define GPIOAEN (1U<<0)
// Bit mask for enabling GPIOc (bit 2)
#define GPIOCEN (1U<<2)

// Alias for PIN5 representing LED pin
#define BTN_PIN (1U<<13)

// Set and reset  LED (pin 5) with BSRR
#define SET_PIN5_BSRR (1U<<5)
#define RESET_PIN5_BSRR (1U<<21)

extern void init_button();
extern void init_led();
extern void set_led();
extern void reset_led();
extern void short_flash();
extern void long_flash();
extern void pause();
extern bool button_pressed();
