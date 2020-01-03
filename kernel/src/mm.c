// MIT License

// Copyright (c) 2018 Alexander Perechnev <alexander@perechnev.com>

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

/*
 * 14MB of memory for free usage.
 *
 * There is also a space from 0x1000000 to whatever exists, but we don't
 * use it yet.
 */
#define MEMORY_BEGIN	(void *)0x04000000
#define MEMORY_END		(void *)0x08000000

k_mm_block_t * first_mb_ptr;

k_mem_size_t memory_block_size(register k_mm_block_t * ptr) {
	return (char *)ptr->end - (char *)ptr->start;
}

k_mm_block_t * memory_find_free_block(register k_mem_size_t size) {
	register k_mm_block_t * m_ptr = first_mb_ptr;
	
	while (m_ptr != K_NULL && (memory_block_size(m_ptr) < size || m_ptr->flags.retained)) {
		m_ptr = m_ptr->next;
	}
	
	return m_ptr;
}

/*
 * Public functions
 */

void k_mm_init() {
	first_mb_ptr = MEMORY_BEGIN;
	first_mb_ptr->start = (char *)MEMORY_BEGIN + sizeof(k_mm_block_t);
	first_mb_ptr->end = MEMORY_END;
	first_mb_ptr->previous = K_NULL;
	first_mb_ptr->next = K_NULL;
	first_mb_ptr->flags.retained = 0;
}

k_mm_block_t * memory_allocate(k_mem_size_t size) {
	k_mm_block_t * m_ptr = memory_find_free_block(size);
	
	if (m_ptr != K_NULL) {
		k_mm_block_t * next = m_ptr->start + size;
		next->start = (char *)next + sizeof(k_mm_block_t);
		next->end = m_ptr->end;
		next->previous = m_ptr;
		next->next = m_ptr->next;
		next->flags.retained = m_ptr->flags.retained;
		
		m_ptr->end = next;
		m_ptr->next = next;
		m_ptr->flags.retained = 1;
	}
	
	return m_ptr;
}

void memory_free(register k_mm_block_t *ptr) {
	register k_mm_block_t * next = ptr->next;
	register k_mm_block_t * previous = ptr->previous;
	
	ptr->flags.retained = 0;
	
	if (next != K_NULL && !next->flags.retained) {
		ptr->end = next->end;
		ptr->next = next->next;
	}
	
	if (previous != K_NULL && !previous->flags.retained) {
		previous->next = ptr->next;
		previous->end = ptr->end;
	}
}
