SOURCES_FOLDER = src/

SOURCE_FILES = $(shell ls $(SOURCES_FOLDER)*/*.c)
OBJECT_FILES = ${SOURCE_FILES:.c=.o}

COMMON_GCC_FLAGS = -nostdlib -nostdinc -I include/ -I ../build/include/ -O0

ifndef ARCH
	ARCH = arm
endif
ifeq ($(ARCH), x86)
	CC = gcc
	AR = ar
	CFLAGS = $(COMMON_GCC_FLAGS)
endif
ifeq ($(ARCH), arm)
	CC = arm-none-eabi-gcc
	AR = arm-none-eabi-gcc-ar
	CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM
endif

all: libc.a

libc.a: $(OBJECT_FILES)
	$(AR) rcs libc.a $?

%.o: %.c
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@

clean:
	rm -f *.core
	rm -f $(SOURCES_FOLDER)*/*.o
	rm -f libc.a
	rm -f tests/*/*.o
	rm -f test_*
