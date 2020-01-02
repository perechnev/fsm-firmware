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

void * __bsearch(
	const void *__key,
	const void *__base,
	__size_t __nmemb,
	__size_t __size,
	__f_compar_t __compar
) {
	if (__nmemb == 0) {
		return __NULL;
	}
	
	if (__nmemb == 1) {
		if (__compar(__key, __base) == 0) {
			return (void *)__base;
		}
		
		return __NULL;
	}
	
	if (__compar(__key, (char *)__base + __nmemb / 2 * __size) < 0) {
		return __bsearch(
			__key,
			__base,
			__nmemb / 2,
			__size,
			__compar
		);
	} else {
		return __bsearch(
			__key,
			(char *)__base + __nmemb / 2  * __size,
			__nmemb - __nmemb / 2,
			__size,
			__compar
		);
	}
	
	return __NULL;
}
