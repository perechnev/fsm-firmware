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
#include <memory.h>

int kcall(int call, int p1) {
	int result = 0;

	__asm__("PUSH {r0-r7}");
    __asm__("MOV r0, %0" : : "r" (call));
	__asm__("MOV r1, %0" : : "r" (p1));
	__asm__("SVC #0x00");
	__asm__("MOV %0, r7" : "=r" (result));
	__asm__("POP {r0-r7}");

	return result;
}

void __attribute__((interrupt("SWI"))) kcall_handler(int r0, int r1, int r2, int r3) {
	int result;

	switch (r0) {
		case KCALL_MEMORY_ALLOCATE:
			result = kcall_memory_allocate(r1);
			break;
		case KCALL_MEMORY_DEALLOCATE:
			kcall_memory_deallocate(r1);
			break;
	}

	__asm__("MOV r7, %0" : : "r" (result));
}

int kcall_memory_allocate(int size) {
	return (int) memory_allocate( (k_mem_size_t)size )->start;
}

void kcall_memory_deallocate(int ptr) {
	k_mm_block_t * m_ptr = (k_mm_block_t *)((char *)ptr - sizeof(k_mm_block_t));
	memory_free(m_ptr);
}
