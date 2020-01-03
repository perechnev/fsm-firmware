// MIT License

// Copyright (c) 2020 Alexander Perechnev <alexander@perechnev.com>

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <kernel.h>
#include <mm.h>

int kcall(int call, int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
	int result = 0;

	__asm__("PUSH {r0-r7}");
	__asm__("MOV r0, %0" : : "r" (p1));
	__asm__("MOV r1, %0" : : "r" (p2));
	__asm__("MOV r2, %0" : : "r" (p3));
	__asm__("MOV r3, %0" : : "r" (p4));
	__asm__("MOV r4, %0" : : "r" (p5));
	__asm__("MOV r5, %0" : : "r" (p6));
	__asm__("MOV r6, %0" : : "r" (p7));
	__asm__("MOV r7, %0" : : "r" (call));
	__asm__("SVC #0x00");
	__asm__("MOV %0, r0" : "=r" (result));
	__asm__("POP {r0-r7}");

	return result;
}

void kcall_handler() {
	int call, p1, p2, p3, p4, p5, p6, p7, result;

	__asm__("MOV %0, r0" : "=r" (p1));
	__asm__("MOV %0, r1" : "=r" (p2));
	__asm__("MOV %0, r2" : "=r" (p3));
	__asm__("MOV %0, r3" : "=r" (p4));
	__asm__("MOV %0, r4" : "=r" (p5));
	__asm__("MOV %0, r5" : "=r" (p6));
	__asm__("MOV %0, r6" : "=r" (p7));
	__asm__("MOV %0, r7" : "=r" (call));

	switch (call) {
		case KCALL_MEMORY_ALLOCATE:
			result = kcall_memory_allocate(p1);
			break;
		case KCALL_MEMORY_DEALLOCATE:
			kcall_memory_deallocate(p1);
			break;
	}

	__asm__("MOV r0, %0" : : "r" (result));
}

int kcall_memory_allocate(int size) {
	return (int) memory_allocate( (k_mem_size_t)size )->start;
}

void kcall_memory_deallocate(int ptr) {
	k_mm_block_t * m_ptr = (k_mm_block_t *)((char *)ptr - sizeof(k_mm_block_t));
	memory_free(m_ptr);
}
