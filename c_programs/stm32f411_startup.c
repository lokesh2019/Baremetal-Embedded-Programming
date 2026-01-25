#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

void Reset_Handler(void);
int main(void);

/* Exception and Interrupt Handlers */
void NMI_Handler					(void) __attribute__ ((weak,alias("Default_Handler")));
void HardFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler 			(void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler 					(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler   				(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler  				(void) __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void TAMP_STAMP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));      
void RTC_WKUP_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));                               
void FLASH_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void RCC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI0_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI1_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void EXTI4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));           
void DMA1_Stream0_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream1_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream2_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream3_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream4_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream5_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void DMA1_Stream6_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));    
void ADC_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));             
void EXTI9_5_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM1_BRK_TIM9_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_UP_TIM10_IRQHandler 		(void) __attribute__ ((weak, alias("Default_Handler")));   
void TIM1_TRG_COM_TIM11_IRQHandler 	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void TIM2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM3_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void TIM4_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void I2C1_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C1_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_EV_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void I2C2_ER_IRQHandler 			(void) __attribute__ ((weak, alias("Default_Handler")));         
void SPI1_IRQHandler  				(void) __attribute__ ((weak, alias("Default_Handler")));           
void SPI2_IRQHandler 				(void) __attribute__ ((weak, alias("Default_Handler")));            
void USART1_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));         
void USART2_IRQHandler  			(void) __attribute__ ((weak, alias("Default_Handler")));        
void EXTI15_10_IRQHandler   		(void) __attribute__ ((weak, alias("Default_Handler")));     
void RTC_Alarm_IRQHandler    		(void) __attribute__ ((weak, alias("Default_Handler")));    
void OTG_FS_WKUP_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void DMA1_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler             	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler     	(void) __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler           	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler          	(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void SPI4_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler"))); 
void SPI5_IRQHandler              	(void) __attribute__ ((weak, alias("Default_Handler"))); 

/* Vector Table */
typedef void (*isr_t)(void);

isr_t vector_tbl[] __attribute__((section(".isr_vector_tbl")))={
	(isr_t)&_estack,
	(isr_t)&Reset_Handler,
	(isr_t)&NMI_Handler,
	(isr_t)&HardFault_Handler,
	(isr_t)&MemManage_Handler,
	(isr_t)&BusFault_Handler,
    (isr_t)&UsageFault_Handler,
    (isr_t)0,
    (isr_t)0,
    (isr_t)0,
    (isr_t)0,
    (isr_t)&SVC_Handler,
    (isr_t)&DebugMon_Handler,
    (isr_t)0,
    (isr_t)&PendSV_Handler,
    (isr_t)&SysTick_Handler,
    (isr_t)&WWDG_IRQHandler,              			/* Window Watchdog interrupt                                          */
    (isr_t)&PVD_IRQHandler,               			/* EXTI Line 16 interrupt / PVD through EXTI                          */
    (isr_t)&TAMP_STAMP_IRQHandler,        			/* Tamper and TimeStamp interrupts through                            */
    (isr_t)&RTC_WKUP_IRQHandler,          			/* RTC Wakeup interrupt through the EXTI line                         */
    (isr_t)&FLASH_IRQHandler,             			/* FLASH global interrupt                                             */
    (isr_t)&RCC_IRQHandler,               			/* RCC global interrupt                                               */
    (isr_t)&EXTI0_IRQHandler,             			/* EXTI Line0 interrupt                                               */
    (isr_t)&EXTI1_IRQHandler,             			/* EXTI Line1 interrupt                                               */
    (isr_t)&EXTI2_IRQHandler,             			/* EXTI Line2 interrupt                                               */
    (isr_t)&EXTI3_IRQHandler,             			/* EXTI Line3 interrupt                                               */
    (isr_t)&EXTI4_IRQHandler,             			/* EXTI Line4 interrupt                                               */
    (isr_t)&DMA1_Stream0_IRQHandler,      			/* DMA1 Stream0 global interrupt                                      */
    (isr_t)&DMA1_Stream1_IRQHandler,      			/* DMA1 Stream1 global interrupt                                      */
    (isr_t)&DMA1_Stream2_IRQHandler,      			/* DMA1 Stream2 global interrupt                                      */
    (isr_t)&DMA1_Stream3_IRQHandler,      			/* DMA1 Stream3 global interrupt                                      */
    (isr_t)&DMA1_Stream4_IRQHandler,      			/* DMA1 Stream4 global interrupt                                      */
    (isr_t)&DMA1_Stream5_IRQHandler,      			/* DMA1 Stream5 global interrupt                                      */
    (isr_t)&DMA1_Stream6_IRQHandler,      			/* DMA1 Stream6 global interrupt                                      */
    (isr_t)&ADC_IRQHandler,               			/* ADC1 global interrupt                                              */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&EXTI9_5_IRQHandler,           			/* EXTI Line[9:5] interrupts                                          */
    (isr_t)&TIM1_BRK_TIM9_IRQHandler,     			/* TIM1 Break interrupt and TIM9 global interrupt                     */
    (isr_t)&TIM1_UP_TIM10_IRQHandler,     			/* TIM1 Update interrupt and TIM10 global interrupt                   */
    (isr_t)&TIM1_TRG_COM_TIM11_IRQHandler,			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    (isr_t)&TIM1_CC_IRQHandler,           			/* TIM1 Capture Compare interrupt                                     */
    (isr_t)&TIM2_IRQHandler,              			/* TIM2 global interrupt                                              */
    (isr_t)&TIM3_IRQHandler,              			/* TIM3 global interrupt                                              */
    (isr_t)&TIM4_IRQHandler,              			/* TIM4 global interrupt                                              */
    (isr_t)&I2C1_EV_IRQHandler,           			/* I2C1 event interrupt                                               */
    (isr_t)&I2C1_ER_IRQHandler,           			/* I2C1 error interrupt                                               */
    (isr_t)&I2C2_EV_IRQHandler,           			/* I2C2 event interrupt                                               */
    (isr_t)&I2C2_ER_IRQHandler,           			/* I2C2 error interrupt                                               */
    (isr_t)&SPI1_IRQHandler,              			/* SPI1 global interrupt                                              */
    (isr_t)&SPI2_IRQHandler,              			/* SPI2 global interrupt                                              */
    (isr_t)&USART1_IRQHandler,            			/* USART1 global interrupt                                            */
    (isr_t)&USART2_IRQHandler,            			/* USART2 global interrupt                                            */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&EXTI15_10_IRQHandler,         			/* EXTI Line[15:10] interrupts                                        */
    (isr_t)&RTC_Alarm_IRQHandler,         			/* RTC Alarms (A and B) through EXTI line interrupt                   */
    (isr_t)&OTG_FS_WKUP_IRQHandler,       			/* USB On-The-Go FS Wakeup through EXTI line interrupt                */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&DMA1_Stream7_IRQHandler,      			/* DMA1 Stream7 global interrupt                                      */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&SDIO_IRQHandler,              			/* SDIO global interrupt                                              */
    (isr_t)&TIM5_IRQHandler,              			/* TIM5 global interrupt                                              */
    (isr_t)&SPI3_IRQHandler,              			/* SPI3 global interrupt                                              */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&DMA2_Stream0_IRQHandler,      			/* DMA2 Stream0 global interrupt                                      */
    (isr_t)&DMA2_Stream1_IRQHandler,      			/* DMA2 Stream1 global interrupt                                      */
    (isr_t)&DMA2_Stream2_IRQHandler,      			/* DMA2 Stream2 global interrupt                                      */
    (isr_t)&DMA2_Stream3_IRQHandler,      			/* DMA2 Stream3 global interrupt                                      */
    (isr_t)&DMA2_Stream4_IRQHandler,      			/* DMA2 Stream4 global interrupt                                      */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&OTG_FS_IRQHandler,            			/* USB On The Go FS global interrupt                                  */
    (isr_t)&DMA2_Stream5_IRQHandler,      			/* DMA2 Stream5 global interrupt                                      */
    (isr_t)&DMA2_Stream6_IRQHandler,      			/* DMA2 Stream6 global interrupt                                      */
    (isr_t)&DMA2_Stream7_IRQHandler,      			/* DMA2 Stream7 global interrupt                                      */
    (isr_t)&USART6_IRQHandler,            			/* USART6 global interrupt                                            */
    (isr_t)&I2C3_EV_IRQHandler,           			/* I2C3 event interrupt                                               */
    (isr_t)&I2C3_ER_IRQHandler,           			/* I2C3 error interrupt                                               */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&FPU_IRQHandler,               			/* FPU global interrupt                                               */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)0,                            			/* Reserved                                                           */
    (isr_t)&SPI4_IRQHandler,              			/* SPI 4 global interrupt                                             */
    (isr_t)&SPI5_IRQHandler              			/* SPI 5 global interrupt */    
};

void Default_Handler(void) {
    while(1){

    }
}

void Reset_Handler(void){
    /* Calculate the sizes of the .data and .bss sections */
    uint32_t data_mem_size = (uint32_t) &_edata - (uint32_t)&_sdata;
    uint32_t bss_mem_size = (uint32_t) &_ebss - (uint32_t)&_sbss;

    /* Initialise pointers to the source and destination of the .data section */
    uint32_t *p_src_mem = (uint32_t *) &_etext;
    uint32_t *p_dest_mem = (uint32_t *) &_sdata;

    /* Copy .data section from FLASH to SRAM */
    for(uint32_t i=0; i < data_mem_size; i++){
        *p_dest_mem++ = *p_src_mem++;
    }

    /* Initialise the .bss section to zero in SRAM */
    p_dest_mem = (uint32_t *)&_sbss;
    for(uint32_t i=0; i<bss_mem_size; i++){
        *p_dest_mem++ = 0; /* Zeroise memory */
    }

    /* All done. Call the application's main() function */
    main();
}
