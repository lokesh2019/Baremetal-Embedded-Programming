#include "uart.h"
// #include "gpio.h"

int main(void){
    /* Initialise debug uart */
    uart_init();
    /* Initialise LED */
    // init_led();
    char *msg = "Hello from the board!!\r\n";

    while(1){
        printf_uart(msg);
        // long_flash();
        // pause();
        for(int i=0; i<10000;i++){}
    }
}
