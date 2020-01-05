ENTRY(__RESET)
SECTIONS
{
	. = 0x00000;
	.ivt .	: { build/ivt.o(.text) }
	.text	: { *(.text) }
	.data	: { *(.data) }
	.bss	: { *(.bss COMMON) }
	. = ALIGN(8);
	. = . + 0x1000; /* 4KB of stack memory */
	stack_top = .;
	. = . + 0x100;
	usr_stack_top = .;

    . = 0x4000000;
	.app_devices : { build/devices.o(.app_devices) }
	. = 0x4000800;
	.app_shell : { build/shell.o(.app_shell) }
	. = 0x4001000;
	.app_timer : { build/timer.o(.app_timer) }
	. = 0x4001000;
	.app_timer : { build/timer.o(.app_timer) }
	. = 0x4001800;
	.app_mmap  : { build/mmap.o(.app_mmap) }
}
