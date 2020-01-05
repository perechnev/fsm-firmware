CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
LD = arm-none-eabi-ld
AS = arm-none-eabi-as

INCLUDE = -I build/include/
COMMON_GCC_FLAGS = -nostdlib -nostdinc -ffreestanding -lc $(INCLUDE) -O0

CFLAGS = $(COMMON_GCC_FLAGS) -mcpu=arm926ej-s -g -D TARGET_ARM

all: framework

framework: build/kernel.a build/libkernel.a build/libc.a build/device.a build/user.a

firmware: build/ivt.o framework build/init.o
	${LD} -o build/firmware.elf -T arch/arm/arm.ld \
		build/ivt.o \
		build/init.o \
		build/user.a \
		build/device.a \
		build/libc.a \
		build/libkernel.a \
		build/kernel.a \
		libgcc.a \

run: firmware
	qemu-system-arm -M versatilepb -m 128M -kernel build/firmware.elf -serial stdio

debug: firmware
	qemu-system-arm -s -S -M versatilepb -m 128M -kernel build/firmware.elf -serial stdio

build/ivt.o:
	${AS} -mcpu=arm926ej-s -g arch/arm/ivt.s -o build/ivt.o

build/init.o:
	${CC} ${CFLAGS} -c -g init.c -o build/init.o

build/kernel.a:
	${MAKE} -C kernel
	mkdir build/include/
	mkdir build/include/kernel/
	cp kernel/include/* build/include/kernel/
	mv build/include/kernel/kernel.h build/include/
	rm build/include/kernel/memory.h
	mv kernel/kernel.a build/

build/libc.a:
	$(MAKE) -C libc
	cp libc/include/* build/include/
	mv libc/libc.a build/

build/libkernel.a:
	$(MAKE) -C libkernel
	cp libkernel/include/* build/include/kernel/
	mv libkernel/libkernel.a build/

build/user.a:
	$(MAKE) -C user
	mv user/user.a build/
	mv user/kill/kill.o build/
	mv user/shell/shell.o build/

build/device.a:
	mkdir -p build/device/
	${CC} ${CFLAGS} -c -g device/PL011/PL011.c -o build/device/PL011.o
	${CC} ${CFLAGS} -c -g device/PL03x/PL03x.c -o build/device/PL03x.o
	${CC} ${CFLAGS} -c -g device/pl110/pl111.c -o build/device/drpl111.o
	${CC} ${CFLAGS} -c -g device/null/null.c -o build/device/null.o
	$(AR) rcs build/device.a build/device/PL011.o build/device/PL03x.o build/device/drpl111.o build/device/null.o
	rm -rf build/device/

	mkdir -p build/include/device/
	cp device/PL011/PL011.h build/include/device/
	cp device/PL03x/PL03x.h build/include/device/
	cp device/pl110/pl111.h build/include/device/
	cp device/null/null.h build/include/device/


clean:
	$(MAKE) clean -C kernel
	$(MAKE) clean -C libc
	$(MAKE) clean -C libkernel
	$(MAKE) clean -C user
	rm -rf build/*
	rm -rf */*.o
