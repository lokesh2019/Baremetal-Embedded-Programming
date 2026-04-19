#ifndef __UART_H__
#define __UART_H__

#include "stm32f4xx.h"

void uart_init(void);
int printf_uart(char *ptr);

#endif
