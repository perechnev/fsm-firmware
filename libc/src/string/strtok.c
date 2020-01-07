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

#include <string.h>
#include <stdlib.h>

char * __strtok_s_ptr;

char * strtok(char * s, const char * delim) {
	char * origin_s_ptr;
	
	if (s != NULL) {
		__strtok_s_ptr = s;
	}
	
	if (__strtok_s_ptr == NULL) {
		return NULL;
	}
	
	while (strchr(delim, *__strtok_s_ptr) != NULL && *__strtok_s_ptr != '\0') {
		__strtok_s_ptr++;
	}
	
	origin_s_ptr = __strtok_s_ptr;
	
	while (*__strtok_s_ptr != '\0') {
		if (strchr(delim, *__strtok_s_ptr) != NULL) {
			break;
		}
		__strtok_s_ptr++;
	}
	
	*__strtok_s_ptr = '\0';
	__strtok_s_ptr++;
	
	if (__strtok_s_ptr > origin_s_ptr) {
		return origin_s_ptr;
	}
	
	return NULL;
}
