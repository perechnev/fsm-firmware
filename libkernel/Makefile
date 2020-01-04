CC = arm-none-eabi-gcc
AR = arm-none-eabi-gcc-ar
CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM

SOURCES_FOLDER = src/

SOURCE_FILES = $(shell ls $(SOURCES_FOLDER)*.c)
OBJECT_FILES = ${SOURCE_FILES:.c=.o}

COMMON_GCC_FLAGS = -nostdlib -nostdinc -I ../build/include/ -O0

all: libkernel.a

libkernel.a: $(OBJECT_FILES)
	$(AR) rcs libkernel.a $?

%.o: %.c
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@

clean:
	rm -f libkernel.a
