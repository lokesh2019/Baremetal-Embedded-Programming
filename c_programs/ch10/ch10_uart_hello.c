#include "uart.h"
#include "gpio.h"

int main(void){
    /* Initialise debug uart */
    uart_init();
    /* Initialise LED */
    init_led();

    char *print = "Hello from the board!\r\n";
    int len = 23;
    while(1){
        for (int i=0; i<len; i++){
            uart_write(print[i]);
            /* Do a short LED burst per letter */
            short_flash();
        }
        /* Long LED burst after each line */
        long_flash();
        pause();
        // printf("Hello from the board!\r\n");
    }
}
