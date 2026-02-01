CC = arm-none-eabi-gcc
INC = -I$(shell pwd) -I$(shell pwd)/chip_headers/CMSIS/Device/ST/STM32F4xx/Include -I$(shell pwd)/chip_headers/CMSIS/Core/Include
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11 -ffreestanding -fno-builtin
LDFLAGS = -T stm32_ls.ld -mcpu=cortex-m4 -mthumb

all: ch2_blink_led.elf ch6_blink_led.elf ch7_gpio_sos.elf ch7_button_led.elf ch8_led_sos.elf ch9_led_blink.elf ch10_uart_hello.elf ch11_voltmeter_adc.elf ch12_adx345_spi.elf

SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(INC) $(CFLAGS) $^ -g -o $@

stm32f411_assembly_startup.o : stm32f411_assembly_startup.s
	$(CC) $(CFLAGS) stm32f411_assembly_startup.s -g -o stm32f411_assembly_startup.o

ch2_blink_led.elf : ch2/ch2_flip_led.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch2_blink_led.map $^ -g -o $@

ch6_blink_led.elf : ch6/ch6_flip_led_CMSIS.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch6_blink_led.map $^ -g -o $@

ch7_gpio_sos.elf : ch7/ch7_led_SOS.o ch7/gpio.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch7_gpio_sos.map $^ -g -o $@

ch7_button_led.elf : ch7/ch7_button_led.o ch7/gpio.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch7_button_led.map $^ -g -o $@

ch8_led_sos.elf : ch8/ch8_led_SOS.o ch8/gpio.o ch8/systick.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch8_led_sos.map $^ -g -o $@

ch9_led_blink.elf: ch9/ch9_led_blink.o ch9/gpio.o ch9/tim.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch9_led_blink.map $^ -g -o $@

ch10_uart_hello.elf: ch10/ch10_uart_hello.o ch10/uart.o stm32f411_assembly_startup.o syscalls.o sysmem.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch10_uart_hello.map $^ -g -o $@

ch11_voltmeter_adc.elf: ch11/ch11_voltmeter_adc.o ch11/uart.o ch11/adc.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch11_voltmeter_adc.map $^ -g -o $@

ch12_adx345_spi.elf: ch12/ch12_adxl345_spi.o ch12/uart.o ch12/adxl345.o ch12/spi.o stm32f411_assembly_startup.o syscalls.o sysmem.o
	$(CC) $(LDFLAGS) -Wl,-Map=ch11_adx345_spi.map $^ -g -o $@

clean:
	rm -rf $(OBJ) *.elf *.map
