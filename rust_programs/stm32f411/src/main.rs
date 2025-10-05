#![no_std]
#![no_main]

/* Create used for pointer arithmatic */
use core::ptr;
use core::panic::PanicInfo;

/* Symbols from the linker script */
unsafe extern "C" {
    static _estack: u32;
    static mut _etext: u32;
    static mut _sdata: u32;
    static mut _edata: u32;
    static mut _sbss: u32;
    static mut _ebss: u32;
}


#[unsafe(no_mangle)]
pub extern "C" fn Reset_Handler() -> ! {
    unsafe{
        let mut data_start = &mut _sdata as *mut u32;
        let data_end = &mut _edata as *mut u32;
        let mut bss_start = &mut _sbss as *mut u32;
        let bss_end = &mut _ebss as *mut u32;
        /* Initialise pointers to the source and destination of the .data section */
        let mut text_end = &mut _etext as *mut u32;

        /* Copy .data section from FLASH to SRAM */
        while data_start < data_end {
            ptr::write(data_start, ptr::read(text_end));
            data_start = data_start.add(1);
            text_end = text_end.add(1);
        }

        /* Erase .bss section to zero in SRAM */
        while bss_start < bss_end {
            ptr::write(bss_start, 0);
            bss_start = bss_start.add(1);
        }
    }


    /* All ready. Now call the main function. */
    main();
}

// Temporary main logic
fn main() -> ! {
    // Access peripherals via raw pointers or PAC here
    loop {
        // Do something
    }
}


#[panic_handler]
fn panic(_info: &PanicInfo) -> ! {
    loop {}
}


/******* 
 * Interrupt vector table setup. No need to change things below this point unless 
 * we are overriding specific intrerrupt handlers.
 *******/
#[unsafe(no_mangle)]
pub extern "C" fn Default_Handler() -> ! {
    loop {}
}


macro_rules! use_default {
    ($_name:ident)=> {
        Default_Handler as u32
    }
}

/* Define vector table. All interrupts use the default handler for simplicity. */
#[unsafe(link_section = ".isr_vector_tbl")]
#[unsafe(no_mangle)]
#[used]
pub static VECTOR_TABLE: [u32; 102] = [
    unsafe { &_estack as *const _ as u32 },
	Reset_Handler as u32,
	use_default!(NMI_Handler),
	use_default!(HardFault_Handler),
	use_default!(MemManage_Handler),
	use_default!(BusFault_Handler),
    use_default!(UsageFault_Handler),
    0,
    0,
    0,
    0,
    use_default!(SVC_Handler),
    use_default!(DebugMon_Handler),
    0,
    use_default!(PendSV_Handler),
    use_default!(SysTick_Handler),
    use_default!(WWDG_IRQHandler),              			/* Window Watchdog interrupt */
    use_default!(PVD_IRQHandler),               			/* EXTI Line 16 interrupt / PVD through EXTI */
    use_default!(TAMP_STAMP_IRQHandler),        			/* Tamper and TimeStamp interrupts through */
    use_default!(RTC_WKUP_IRQHandler),          			/* RTC Wakeup interrupt through the EXTI line */
    use_default!(FLASH_IRQHandler),             			/* FLASH global interrupt */
    use_default!(RCC_IRQHandler),               			/* RCC global interrupt */
    use_default!(EXTI0_IRQHandler),             			/* EXTI Line0 interrupt */
    use_default!(EXTI1_IRQHandler),             			/* EXTI Line1 interrupt */
    use_default!(EXTI2_IRQHandler),             			/* EXTI Line2 interrupt */
    use_default!(EXTI3_IRQHandler),             			/* EXTI Line3 interrupt */
    use_default!(EXTI4_IRQHandler),             			/* EXTI Line4 interrupt */
    use_default!(DMA1_Stream0_IRQHandler),      			/* DMA1 Stream0 global interrupt */
    use_default!(DMA1_Stream1_IRQHandler),      			/* DMA1 Stream1 global interrupt */
    use_default!(DMA1_Stream2_IRQHandler),      			/* DMA1 Stream2 global interrupt */
    use_default!(DMA1_Stream3_IRQHandler),      			/* DMA1 Stream3 global interrupt */
    use_default!(DMA1_Stream4_IRQHandler),      			/* DMA1 Stream4 global interrupt */
    use_default!(DMA1_Stream5_IRQHandler),      			/* DMA1 Stream5 global interrupt */
    use_default!(DMA1_Stream6_IRQHandler),      			/* DMA1 Stream6 global interrupt */
    use_default!(ADC_IRQHandler),               			/* ADC1 global interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(EXTI9_5_IRQHandler),           			/* EXTI Line[9:5] interrupts */
    use_default!(TIM1_BRK_TIM9_IRQHandler),     			/* TIM1 Break interrupt and TIM9 global interrupt */
    use_default!(TIM1_UP_TIM10_IRQHandler),     			/* TIM1 Update interrupt and TIM10 global interrupt */
    use_default!(TIM1_TRG_COM_TIM11_IRQHandler),			/* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    use_default!(TIM1_CC_IRQHandler),           			/* TIM1 Capture Compare interrupt */
    use_default!(TIM2_IRQHandler),              			/* TIM2 global interrupt */
    use_default!(TIM3_IRQHandler),              			/* TIM3 global interrupt */
    use_default!(TIM4_IRQHandler),              			/* TIM4 global interrupt */
    use_default!(I2C1_EV_IRQHandler),           			/* I2C1 event interrupt */
    use_default!(I2C1_ER_IRQHandler),           			/* I2C1 error interrupt */
    use_default!(I2C2_EV_IRQHandler),           			/* I2C2 event interrupt */
    use_default!(I2C2_ER_IRQHandler),           			/* I2C2 error interrupt */
    use_default!(SPI1_IRQHandler),              			/* SPI1 global interrupt */
    use_default!(SPI2_IRQHandler),              			/* SPI2 global interrupt */
    use_default!(USART1_IRQHandler),            			/* USART1 global interrupt */
    use_default!(USART2_IRQHandler),            			/* USART2 global interrupt */
    0,                            			/* Reserved */
    use_default!(EXTI15_10_IRQHandler),         			/* EXTI Line[15:10] interrupts */
    use_default!(RTC_Alarm_IRQHandler),         			/* RTC Alarms (A and B) through EXTI line interrupt */
    use_default!(OTG_FS_WKUP_IRQHandler),       			/* USB On-The-Go FS Wakeup through EXTI line interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(DMA1_Stream7_IRQHandler),      			/* DMA1 Stream7 global interrupt */
    0,                            			/* Reserved */
    use_default!(SDIO_IRQHandler),              			/* SDIO global interrupt */
    use_default!(TIM5_IRQHandler),              			/* TIM5 global interrupt */
    use_default!(SPI3_IRQHandler),              			/* SPI3 global interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(DMA2_Stream0_IRQHandler),      			/* DMA2 Stream0 global interrupt */
    use_default!(DMA2_Stream1_IRQHandler),      			/* DMA2 Stream1 global interrupt */
    use_default!(DMA2_Stream2_IRQHandler),      			/* DMA2 Stream2 global interrupt */
    use_default!(DMA2_Stream3_IRQHandler),      			/* DMA2 Stream3 global interrupt */
    use_default!(DMA2_Stream4_IRQHandler),      			/* DMA2 Stream4 global interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(OTG_FS_IRQHandler),            			/* USB On The Go FS global interrupt */
    use_default!(DMA2_Stream5_IRQHandler),      			/* DMA2 Stream5 global interrupt */
    use_default!(DMA2_Stream6_IRQHandler),      			/* DMA2 Stream6 global interrupt */
    use_default!(DMA2_Stream7_IRQHandler),      			/* DMA2 Stream7 global interrupt */
    use_default!(USART6_IRQHandler),            			/* USART6 global interrupt */
    use_default!(I2C3_EV_IRQHandler),           			/* I2C3 event interrupt */
    use_default!(I2C3_ER_IRQHandler),           			/* I2C3 error interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(FPU_IRQHandler),               			/* FPU global interrupt */
    0,                            			/* Reserved */
    0,                            			/* Reserved */
    use_default!(SPI4_IRQHandler),              			/* SPI 4 global interrupt */
    use_default!(SPI5_IRQHandler)                		    /* SPI 5 global interrupt */    
];
