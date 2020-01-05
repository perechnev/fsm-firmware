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
	.app_kill  : { build/kill.o(.app_kill) }
}
