#include "uart.h"

int main(void){
    /* Initialise debug uart */
    uart_init();
    char *msg = "Hello from the board!!\r\n";

    while(1){
        printf_uart(msg);
        for(int i=0; i<10000;i++){}
    }
}
