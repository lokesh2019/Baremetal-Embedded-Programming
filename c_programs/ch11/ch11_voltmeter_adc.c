#include "uart.h"
#include "adc.h"

/**
 * Converts a positive integer to a string without library functions.
 * @param num: The positive integer to convert.
 * @param str: Buffer to store the string (must be large enough).
 */
void uint_to_string(unsigned int num, char* str) {
    int i = 0;

    // 1. Handle zero explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\r';
        str[i+1] = '\n';
        str[i+2] = '\0';
        return;
    }

    // 2. Extract digits in reverse order
    // (e.g., 123 becomes "321")
    while (num > 0) {
        str[i++] = (num % 10) + '0'; // Get last digit and convert to ASCII
        num /= 10;                   // Remove last digit
    }

    str[i] = '\r';
    str[i+1] = '\n';
    str[i+2] = '\0'; // Null-terminate the string

    // 3. Reverse the string in place to get "123"
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main(void){
    int sensor_value;
    char sensor_value_str[10] = {0};
    /* Initialise debug uart */
    uart_init();

    /* Initialise ADC */
    pa1_adc_init();

    /* Start conversion*/
    start_conversion();

    while(1){
        sensor_value = adc_read();
        uint_to_string(sensor_value, sensor_value_str);
        printf_uart(sensor_value_str);
    }
}
