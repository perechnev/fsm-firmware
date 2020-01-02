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

void __qsort(
	void *__base,
	__size_t __nmemb,
	__size_t __size,
	__f_compar_t __compar
) {
	char * ch_base = (char *)__base;
	void * b;
	int i = 0, j = 0;
	unsigned long t;
	
	if (__nmemb < 2) {
		return;
	}
	
	b = ch_base + (__nmemb - 1) * __size;
	
	while (j < __nmemb) {
		if (__compar((const void *)(ch_base + j * __size), b) <= 0) {
			__memcpy(&t, ch_base + j * __size, __size);
			__memmove(ch_base + (i + 1) * __size, ch_base + i * __size, (j - i) * __size);
			__memcpy(ch_base + i * __size, &t, __size);
			
			i++;
		}
		
		j++;
	}
	
	__qsort(__base, i - 1, __size, __compar);
	__qsort(ch_base + i * __size, j - i, __size, __compar);
}
