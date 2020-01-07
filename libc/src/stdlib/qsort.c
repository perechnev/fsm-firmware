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


#include <stdlib.h>
#include <stddef.h>
#include <string.h>

void qsort(void * base, size_t nmemb, size_t size, f_compar_t compar) {
	char * ch_base = (char *)base;
	void * b;
	int i = 0, j = 0;
	unsigned long t;
	
	if (nmemb < 2) {
		return;
	}
	
	b = ch_base + (nmemb - 1) * size;
	
	while (j < nmemb) {
		if (compar((const void *)(ch_base + j * size), b) <= 0) {
			memcpy(&t, ch_base + j * size, size);
			memmove(ch_base + (i + 1) * size, ch_base + i * size, (j - i) * size);
			memcpy(ch_base + i * size, &t, size);
			
			i++;
		}
		
		j++;
	}
	
	qsort(base, i - 1, size, compar);
	qsort(ch_base + i * size, j - i, size, compar);
}
