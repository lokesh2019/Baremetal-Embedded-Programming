#include "spi.h"
#define SPI1EN    (1U<<12)
#define GPIOAEN   (1U<<0)
#define SR_TXE    (1U<<1)
#define SR_RXNE   (1U<<0)
#define SR_BSY    (1U<<7)

/*
* According to the datasheet, the STM32F411CE board has SPI1,2,3,4,5 - we are going to use SPI1.
* RM0383 chapter 20, Figure 193 is the one we want - one master, one slave. It needs 4 pins:
* (1) MISO (2) MOSI (3) SCK (4) NSS
* In the datasheet Chapter-4 pinouts, table-7, these are the matching pins:
* (1) PA4 - SPI1_NSS
* (2) PA5 - SPI1_SCK
* (3) PA6 - SPI1_MISO
* (4) PA7 - SPI1_MOSI
* The code below actually use PA9 as the output pin to act as chip select.
* These are all on Port-A. GPIOA is on AHB1 bus. UM1724, Table 16 has all the pin name mappings.

* According to the Reference Manual RM0383, the SPI1 registers are on APB2 Bus.
* 
*/

void spi_gpio_init(void){
    /* Enable clock access to GPIOA */
    RCC->AHB1ENR |= GPIOAEN;

    /* Set PA5, PA6, PA7 mode to alternate function (10 = Alternate function mode) */

    /* PA5 */
    GPIOA->MODER &= ~(1U<<10);
    GPIOA->MODER |= (1U<<11);

    /* PA6 */
    GPIOA->MODER &= ~(1U<<12);
    GPIOA->MODER |= (1U<<13);

    /* PA7 */
    GPIOA->MODER &= ~(1U<<14);
    GPIOA->MODER |= (1U<<15);

    /* Set PA9 as output pin to act as chip select - we don't use the PA4=NSS pin */
    GPIOA->MODER |= (1U<<18);
    GPIOA->MODER &= ~(1U<<19);

    /* Set PA5, PA6, PA7 alternate function type to SPI1 (Mode AF05 (SPI1 in datasheet) = 0101) */
    /* PA5 */
    GPIOA->AFR[0] |= (1U<<20);
    GPIOA->AFR[0] &= ~(1U<<21);
    GPIOA->AFR[0] |= (1U<<22);
    GPIOA->AFR[0] &= ~(1U<<23);

    /* PA6 */
    GPIOA->AFR[0] |= (1U<<24);
    GPIOA->AFR[0] &= ~(1U<<25);
    GPIOA->AFR[0] |= (1U<<26);
    GPIOA->AFR[0] &= ~(1U<<27);

    /* PA7 */
    GPIOA->AFR[0] |= (1U<<28);
    GPIOA->AFR[0] &= ~(1U<<29);
    GPIOA->AFR[0] |= (1U<<30);
    GPIOA->AFR[0] &= ~(1U<<31);

}

void spi1_config(void){
    /* Enable clock access to SPI1 module */
    RCC->APB2ENR |= SPI1EN;

    /* Set clock to fPCLK/4 (=001 in RM)*/
    SPI1->CR1 |= (1U<<3);
    SPI1->CR1 &= ~(1U<<4);
    SPI1->CR1 &= ~(1U<<5);

    /* Set CPOL to 1 and CPHA to 1 */
    SPI1->CR1 |= (1U<<0);
    SPI1->CR1 |= (1U<<1);

    /* Enable full duplex */
    SPI1->CR1 &= ~(1U<<10);

    /* Set MSB first*/
    SPI1->CR1 &= ~(1U<<7);

    /* Set mode to MASTER */
    SPI1->CR1 |= (1U<<2);

    /* Set 8 bit data mode */
    SPI1->CR1 &= ~(1U<<11);

    /* Select software slave management by setting SSM=1, SSI=1 */
    SPI1->CR1 |= (1U<<8);
    SPI1->CR1 |= (1U<<9);

    /* Enable SPI module */

    SPI1->CR1 |= (1<<6);
}

void spi1_transmit(uint8_t *data, uint32_t size){
    uint32_t i=0;
    uint8_t temp;
    while(i<size){
        /* Wait until TXE is set */
        while(!(SPI1->SR & SR_TXE)){}

        /* Write the data to the data register */
        SPI1->DR = data[i];
        i++;
    }

    /* Wait until TXE is set */
    while(!(SPI1->SR & SR_TXE)){}

    /* Wait for BUSY flag to reset */
    while((SPI1->SR & (SR_BSY))){}

    /* Clear OVR flag */
    temp = SPI1->DR;
    temp = SPI1->SR;
}

void spi1_receive(uint8_t *data, uint32_t size){
    while(size){
        /* Send dummy data */
        SPI1->DR = 0;
        /* Wait for RXNE flag to be set */
        while(!(SPI1->SR & (SR_RXNE))){}
        /* Read data from the data register */
        *data = (SPI1->DR);
        data++;
        size--;
    }
}

void cs_enable(void){
    GPIOA->ODR &= ~(1U<<9);
}

/* Pull high to disable */
void cs_disable(void){
    GPIOA->ODR |= (1U<<9);
}
