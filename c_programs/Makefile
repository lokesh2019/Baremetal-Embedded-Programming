CC = arm-none-eabi-gcc
INC = -I$(shell pwd)
CFLAGS = -c -mcpu=cortex-m4 -mthumb -std=gnu11
LDFLAGS = -nostdlib -T stm32_ls.ld -Wl,-Map=ch2_flip_led.map

all: blink_led.elf

SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(INC) $(CFLAGS) $^ -o $@

blink_led.elf : ch2/ch2_flip_led.o stm32f411_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ) *.elf *.map
