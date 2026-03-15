#ifndef __IWDG_H__
#define __IWDG_H__

#include <stdint.h>
#include "stm32f4xx.h"

#define IWDG_KEY_ENABLE             0x0000CCCCU
#define IWDG_KEY_RELOAD             0x0000AAAAU
#define IWDG_KEY_WR_ACCESS_ENABLE   0x00005555U
#define IWDG_PRESCALER_4            0x00000000U
#define IWDG_RELOAD_VAL             0xFFF

void iwdg_init(void);

#endif