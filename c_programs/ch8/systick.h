#ifndef _SYSTICK_H
#define _SYSTICK_H

#include <stdint.h>
#include "stm32f4xx.h"

void systick_msec_delay(uint32_t delay);

#endif /* _SYSTICK_H */
