ENTRY(__RESET)
SECTIONS
{
	. = 0x10000;
	.ivt .	: { build/ivt.o(.text) }
	.text	: { *(.text) }
	.data	: { *(.data) }
	.bss	: { *(.bss COMMON) }
	. = ALIGN(8);
	. = . + 0x1000; /* 4KB of stack memory */
	stack_top = .;
}
