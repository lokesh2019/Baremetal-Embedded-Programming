#include "uart.h"
#include <stdio.h>

int main(void){
    /* Initialise debug uart */
    uart_init();
    char *msg = "Hello from the board!!";
    int i = 0;
    while(1){
        printf("%s -- %d \r \n", msg, i++);
        for(int i=0; i<10000;i++){}
    }
}
