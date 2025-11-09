#ifndef _TIM_H
#define _TIM_H

#include <stdint.h>
#include "stm32f4xx.h"

#define SR_UIF (1U<<0)

void tim2_1hz_init(void);

#endif /* _TIM_H */
