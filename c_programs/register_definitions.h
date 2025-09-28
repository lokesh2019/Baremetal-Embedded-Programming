/* Peripherals Base Address */
#define PERIPH_BASE (0x40000000UL)
/* Offset for AHB1 peripheral bus */
#define AHB1PERIPH_OFFSET (0x00020000UL)
/* Base address for AHB1 peripberals */
#define AHB1PERIPH_BASE (PERIPH_BASE + AHB1PERIPH_OFFSET)
/* Offset for GPIOA */
#define GPIOA_OFFSET (0x0000UL)
/* Base address for GPIOA */
#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)
/* Offset for RCC */
#define RCC_OFFSET (0x3800UL)
/* Base address for RCC */
#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)
/* Offset for AHB1EN Register */
#define AHB1EN_R_OFFSET (0x30UL)
/* Address of AHB1EN register*/
#define RCC_AHB1EN_R (*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
/* Offset for mode register */
#define MODE_R_OFFSET (0x00UL)
/* Address of GPIOA mode register */
#define GPIOA_MODE_R (*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
/* Offset for output data register */
#define OD_R_OFFSET (0x14UL)
/* Address of GPIOA output data register */
#define GPIOA_OD_R (*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))
/* Bit mask for enabling GPIOA (bit 0) */
#define GPIOAEN (1U<<0)
/* Bit mask for GPIOA pin 5 */
#define PIN5 (1U<<5)
/* Alias for PIN5 representing LED pin */
#define LED_PIN PIN5
