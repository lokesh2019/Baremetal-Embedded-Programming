#include <stdio.h>
#include "rtc.h"
#include "uart.h"

#define BUFF_LEN              20

uint8_t time_buff[BUFF_LEN] = {0};
uint8_t date_buff[BUFF_LEN] = {0};

static void display_rtc_calendar(void);

int main(){
    /* Initialise debug UART */
    uart_init();

    /* Initialise_rtc */
    rtc_init();

    while(1){
        display_rtc_calendar();
    }
}

static void display_rtc_calendar(void){
    /* Display format: hh:mm:ss */
    snprintf((char*)time_buff, BUFF_LEN, "Time: %.2d:%.2d:%.2d",
                rtc_convert_bcd2dec(rtc_time_get_hour()),
                rtc_convert_bcd2dec(rtc_time_get_minute()),
                rtc_convert_bcd2dec(rtc_time_get_second())
            ); 

    /* Display format: DD:MM:YY */
    snprintf((char*)date_buff, BUFF_LEN, "Date: %.2d-%.2d-%.2d",
                rtc_convert_bcd2dec(rtc_date_get_day()),
                rtc_convert_bcd2dec(rtc_date_get_month()),
                rtc_convert_bcd2dec(rtc_date_get_year())
            );

    printf("%s   %s\r\n", date_buff, time_buff);
}
