CC = arm-none-eabi-gcc
INC = -I$(shell pwd) -I$(shell pwd)/chip_headers/CMSIS/Device/ST/STM32F4xx/Include -I$(shell pwd)/chip_headers/CMSIS/Core/Include
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=ch2_flip_led.map

all: ch2_blink_led.elf ch6_blink_led.elf ch7_gpio_sos.elf ch7_button_led.elf ch8_led_sos.elf ch9_led_blink.elf ch10_uart_hello.elf

SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(INC) $(CFLAGS) $^ -g -o $@

ch2_blink_led.elf : ch2/ch2_flip_led.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch6_blink_led.elf : ch6/ch6_flip_led_CMSIS.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch7_gpio_sos.elf : ch7/ch7_led_SOS.o ch7/gpio.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch7_button_led.elf : ch7/ch7_button_led.o ch7/gpio.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch8_led_sos.elf : ch8/ch8_led_SOS.o ch8/gpio.o ch8/systick.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch9_led_blink.elf: ch9/ch9_led_blink.o ch9/gpio.o ch9/tim.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

ch10_uart_hello.elf: ch10/ch10_uart_hello.o ch10/uart.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -g -o $@

clean:
	rm -rf $(OBJ) *.elf *.map
