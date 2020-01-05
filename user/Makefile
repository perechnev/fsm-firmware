CC = arm-none-eabi-gcc
AR = arm-none-eabi-gcc-ar

INCLUDE = -I ../build/include/
COMMON_GCC_FLAGS = -nostdlib -nostdinc -ffreestanding -lc $(INCLUDE) -O0
CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM

SRC = apps/apps.c devices/devices.c mmap/mmap.c shell/shell.c tasks/tasks.c timer/timer.c
OBJ = ${SRC:.c=.o}

all: $(OBJ)
	$(AR) rcs user.a $?
	$(CC) $(CFLAGS) -c kill/kill.c -o kill/kill.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f */*.o
	rm -f *.o
