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


#include <stddef.h>

void * memmove(void * dest, const void * src, size_t n) {
	char * dst_ptr = (char *)dest;
	char * src_ptr = (char *)src;
	
	register int i;
	
	if (dst_ptr < src_ptr) {
		for (i = 0; i < n; i++) {
			dst_ptr[i] = src_ptr[i];
		}
	}
	else {
		for (i = n - 1; i >= 0; i--) {
			dst_ptr[i] = src_ptr[i];
		}
	}
	
	return dest;
}
