#include<stdint.h>
#include "uart.h"

#define GPIOAEN (1U<<0)  // This is to enable clock to GPIOA
#define UART2EN (1U<<17) // This is to enable clock to UART2

#define DBG_UART_BAUDRATE 115200
#define SYS_FREQ 16*1000*1000
#define APB1_CLK SYS_FREQ
/* CR1 bits are from USART_CR1 register */
#define CR1_TE (1U<<3)
#define CR1_UE (1U<<13)
/* SR bit is from USART_SR register */
#define SR_TXE (1U<<7)

static void uart_set_baudrate(uint32_t preiph_clk, uint32_t baudrate);
static void uart_write(int ch);

int printf_uart(char *ptr)
{
    int ctr = 0;
    while (*ptr != 0){
        uart_write(*ptr);
        ptr++;
        ctr++;
    }
    return ctr;
}

void uart_init(void){
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set the mode of PA2 to alternate function mode. Basically set mode for pin-2 to 10=AF */
    GPIOA->MODER &= ~(1U<<4);
    GPIOA->MODER |= (1U<<5);

    /* Set alternative function type to AF7=0111 (UART2_TX) */
    /* Each AF value is 4 bits and there are 16 bits. To fit them all (=64bits), there are two AFRs of 32-bit each: AFRL (Low for 0-7) and AFRH (High for 8-15) */
    /* AFR[0] refers to AFRL, and sets pins 8-11 which are for AFRL2 == PA2 */
    GPIOA->AFR[0] |= (1U<<8);
    GPIOA->AFR[0] |= (1U<<9);
    GPIOA->AFR[0] |= (1U<<10);
    GPIOA->AFR[0] &= ~(1U<<11);

    /* Enable clock access to UART2 */
    RCC->APB1ENR |= UART2EN;

    /* Configure UART baudrate */
    uart_set_baudrate(APB1_CLK, DBG_UART_BAUDRATE);

    /* Configure uart baudrate */
    USART2->CR1 = CR1_TE;

    /* Enable UART Module */
    USART2->CR1 |= CR1_UE;
}

static void uart_write(int ch){
    /* Make sure transmit data register is empty */
    while(!(USART2->SR & SR_TXE)){}

    /* Write to transmit data register */
    USART2->DR = (ch & 0xFF);
}

int __io_putchar(int ch)
{
    uart_write(ch);
    return ch;
}

static uint16_t compute_uart_bd(uint32_t periph_clk, uint32_t baudrate){
    return ((periph_clk + (baudrate/2U))/baudrate);
}

static void uart_set_baudrate(uint32_t periph_clk, uint32_t baudrate){
    USART2->BRR = compute_uart_bd(periph_clk, baudrate);
}
