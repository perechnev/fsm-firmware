CC = arm-none-eabi-gcc
AR = arm-none-eabi-gcc-ar

INCLUDE = -I ../build/include/
COMMON_GCC_FLAGS = -nostdlib -nostdinc -ffreestanding -lc $(INCLUDE) -O0
CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM

SRC = $(shell ls */*.c)
OBJ = ${SRC:.c=.o}

all: $(OBJ)
	$(AR) rcs user.a $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f */*.o
	rm -f *.o
