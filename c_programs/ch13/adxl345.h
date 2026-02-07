#ifndef __ADXL345_H__
#define __ADXL345_H__

#include <stdint.h>
#include "i2c.h"

/* Constants copied from the book. See manual for more info: https://www.analog.com/media/en/technical-documentation/data-sheets/adxl345.pdf */
#define ADXL345_REG_DEVID (0x00)
#define ADXL345_DEVICE_ADDR (0x53)
#define ADXL345_REG_DATA_FORMAT (0x31)
#define ADXL345_REG_POWER_CTL (0x2D)
#define ADXL345_REG_DATA_START (0x32)

#define ADXL345_RANGE_4G (0x01)
#define ADXL345_RESET (0x00)
#define ADXL345_MEASURE_BIT (0x08)

void adxl_init(void);
void adxl_read_values(uint8_t reg);
#endif
