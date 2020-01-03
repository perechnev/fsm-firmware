# MIT License
#
# Copyright (c) 2018 Alexander Perechnev <alexander@perechnev.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

.global __RESET

__RESET:
	B		RESET_HANDLER /* Reset */
	B		. /* Undefined */
	B		SWI_HANDLER	/* SWI */
	B		. /* Prefetch Abort */
	B		. /* Data Abort */
	B		. /* reserved */
	B		. /* IRQ */
	B		. /* FIQ */

RESET_HANDLER:
    MSR     CPSR_c, 0x13 /* Supervisor mode */
	LDR		SP, =stack_top
	MSR		CPSR_c, 0x10 /* User mode */
	LDR		SP, =usr_stack_top
	BL		init
	B		.

SWI_HANDLER:
	PUSH	{LR}
	BL		kcall_handler
	POP		{LR}
	MOVS	PC, LR /* Return from supervisor mode */
