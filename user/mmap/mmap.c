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

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char * start;
	char * end;
	
	struct k_mm_block_t * previous;
	struct k_mm_block_t * next;
	
	struct {
		char retained : 1;
	} flags;
} k_mm_block_t;

extern k_mm_block_t * first_mb_ptr;

char buffer[32];

void print_block(k_mm_block_t * ptr) {
	itoa(ptr, buffer, 16); puts(buffer); puts("\t");
	itoa(ptr->start, buffer, 16); puts(buffer); puts("\t");
	itoa(ptr->end, buffer, 16); puts(buffer); puts("\t");
	
	if (ptr->flags.retained == 0) {
		puts("Free");
	} else {
		puts("Used");
	}
	puts("\t");
	
	itoa(ptr->end - ptr->start, buffer, 10); puts(buffer); puts("\t");
	
	puts("\r\n");
}

int __attribute__((section(".app_mmap"))) mmap_entry(int process_id, int state) {
	itoa(sizeof(k_mm_block_t), buffer, 10);
	puts("Size of k_mm_block_t = ");
	puts(buffer);
	puts("\r\n");
	
	puts("Block\t\tStart\t\tEnd\t\tStatus\tSize\r\n");
	
	k_mm_block_t * ptr = first_mb_ptr;
	
	while (ptr != NULL) {
		print_block(ptr);
		ptr = ptr->next;
	}

    return 0;
}
