!#[no_std]
!#[no_main]

use panic_halt as _;
fn default_handler() {
    while True {}
}

fn Reset_Handler() -> ! {
    unsafe {
        /* Calculate the sizes of the .data and .bss sections */
        u32 data_mem_size = (u32)&_edata - (u32)&_sdata;
        u32 bss_mem_size = (u32)&_ebss - (u32)&_sbss;

        /* Initialise pointers to the source and destination of the .data section */
        u32 *p_src_mem = (u32 *) &_etext;
        u32 *p_dest_mem = (u32 *) &_sdata;

        /* Copy .data section from FLASH to SRAM */
        for(u32 i=0; i < data_mem_size; i++){
            *p_dest_mem++ = *p_src_mem;
        }

        /* Initialise teh .bss section to zero in SRAM */
        p_dest_mem = (u32 *)&_sbss;
        for(u32 i=0; i<bss_mem_size; i++){
            *p_dest_mem++ = 0; /* Zeroise memory */
        }
    }

    main();
}
