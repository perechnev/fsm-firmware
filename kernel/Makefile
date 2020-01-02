SOURCES_FOLDER = src/
INCLUDE_FOLDER = include/

SOURCE_FILES = $(shell ls $(SOURCES_FOLDER)*.c)
OBJECT_FILES = ${SOURCE_FILES:.c=.o}

COMMON_GCC_FLAGS = -nostdlib -nostdinc -I $(INCLUDE_FOLDER) -O0

CC = arm-none-eabi-gcc
AR = arm-none-eabi-gcc-ar
CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM

all: kernel.a

kernel.a: $(OBJECT_FILES)
	$(AR) rcs kernel.a $?

%.o: %.c
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@

clean:
	rm -f kernel.a
	rm -f $(SOURCES_FOLDER)*.o
