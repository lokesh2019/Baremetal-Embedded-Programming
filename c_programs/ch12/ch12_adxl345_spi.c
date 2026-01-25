#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#include "spi.h"
#include "adxl345.h"


/* Variables for storing accelerometer data */
int16_t accel_x, accel_y, accel_z;
double accel_x_g, accel_y_g, accel_z_g;

uint8_t data_buffer[6];

int main(void){
    char x[10], y[10], z[10];
    /* Initialise debug uart */
    uart_init();
    /* Initialise ADDXL345 accelerometer */
    adxl_init();

    while(1){
        /* Read accelerometer data starting from the data start register */
        adxl_read(ADXL345_DATA_START, data_buffer);

        /* Combine high and low bytes to form the accelerometer data */
        accel_x = (int16_t) (data_buffer[1] << 8 | data_buffer[0]);
        accel_y = (int16_t) (data_buffer[3] << 8 | data_buffer[2]);
        accel_z = (int16_t) (data_buffer[5] << 8 | data_buffer[4]);

        printf("x=%d, y=%d, z=%d\r\n",accel_x, accel_y, accel_y);
    }
}
