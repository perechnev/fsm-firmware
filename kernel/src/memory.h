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

#ifndef __KERNEL_MEMORY_H__
#define __KERNEL_MEMORY_H__

typedef int k_mem_size_t;

typedef struct {
	char * start;
	char * end;
	
	struct k_mm_block_t * previous;
	struct k_mm_block_t * next;
	
	int retain_count;
} k_mm_block_t;

void	k_mm_init	();

k_mm_block_t *	memory_allocate(k_mem_size_t size);
int             memory_retain(void * ptr);
void			memory_free(k_mm_block_t * ptr);
k_mem_size_t	memory_block_size(k_mm_block_t * ptr);

#endif /* __KERNEL_MEMORY_H__ */
