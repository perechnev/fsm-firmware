SOURCES_FOLDER = src/

SOURCE_FILES = $(shell ls $(SOURCES_FOLDER)*/*.c)
OBJECT_FILES = ${SOURCE_FILES:.c=.o}

COMMON_GCC_FLAGS = -nostdlib -nostdinc -I include/ -I ../build/include/ -O0


# Deal with platform

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


# Building

all: libc.a

libc.a: $(OBJECT_FILES)
	$(AR) rcs libc.a $?

%.o: %.c
	$(CC) $(CFLAGS) -ffreestanding -c $< -o $@


# Tests

STRING_TEST_SRC = $(shell ls tests/string/*.c)
STRING_TEST_OBJ = ${STRING_TEST_SRC:.c=.o}

STDLIB_TEST_SRC = $(shell ls tests/stdlib/*.c)
STDLIB_TEST_OBJ = ${STDLIB_TEST_SRC:.c=.o}

MATH_TEST_SRC = $(shell ls tests/math/*.c)
MATH_TEST_OBJ = ${MATH_TEST_SRC:.c=.o}

STDIO_TEST_SRC = $(shell ls tests/stdio/*.c)
STDIO_TEST_OBJ = ${STDIO_TEST_SRC:.c=.o}

CTYPE_TEST_SRC = $(shell ls tests/ctype/*.c)
CTYPE_TEST_OBJ = ${CTYPE_TEST_SRC:.c=.o}

test_string: $(STRING_TEST_SRC) libc.a
	$(CC) -l cmocka $? -o $@

test_stdlib: $(STDLIB_TEST_SRC) libc.a
	$(CC) -l cmocka $? -o $@

test_math: $(MATH_TEST_SRC) libc.a
	$(CC) -l cmocka $? -o $@

test_stdio: $(STDIO_TEST_SRC) libc.a
	$(CC) -l cmocka $? -o $@

test_ctype: $(CTYPE_TEST_SRC) libc.a
	$(CC) -l cmocka $? -o $@

test: test_stdlib test_math test_stdio test_ctype test_string
	./test_string
	./test_ctype
	./test_stdio
	./test_stdlib
	./test_math


# Clean

clean:
	rm -f *.core
	rm -f $(SOURCES_FOLDER)*/*.o
	rm -f libc.a
	rm -f tests/*/*.o
	rm -f test_*
