#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "i2c.h"
#include "adxl345.h"


/* Variables for storing accelerometer data */
int16_t accel_x, accel_y, accel_z;
double accel_x_g, accel_y_g, accel_z_g;

extern uint8_t data_buffer[6];

int main(void){
    /* Initialise debug uart */
    uart_init();
    printf("UART initialised\r\n");
    /* Initialise ADDXL345 accelerometer */
    adxl_init();
    printf("ADXL initialised\r\n");

    while(1){
        /* Read accelerometer data starting from the data start register */
        adxl_read_values(ADXL345_REG_DATA_START);

        /* Combine high and low bytes to form the accelerometer data */
        accel_x = (int16_t) (data_buffer[1] << 8 | data_buffer[0]);
        accel_y = (int16_t) (data_buffer[3] << 8 | data_buffer[2]);
        accel_z = (int16_t) (data_buffer[5] << 8 | data_buffer[4]);

        printf("x=%d, y=%d, z=%d\r\n",accel_x, accel_y, accel_y);
    }
}
