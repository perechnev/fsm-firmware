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
#include <string.h>

char * __revert(char *s) {
	int i, j;
	char tmp;
	
	for (i = 0, j = __strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	
	return s;
}

void * __itoa(int input, char * buffer, int radix) {
	char * beginning = buffer;
	int digit;
	
	if (input == 0) {
		*buffer = '0'; buffer++;
	} else {
		while (input % radix > 0 || input / radix > 0) {
			digit = input % radix;
			*buffer = '0' + digit;
			if (digit > 9) {
				*buffer += 7;
			}
			input /= radix;
			buffer++;
		}
	}
	
	if (radix == 16) {
		*buffer = 'x'; buffer++; 
		*buffer = '0'; buffer++;
	} else if (radix == 2) {
		*buffer = 'b'; buffer++;
		*buffer = '0'; buffer++;
	}
	
	*buffer = '\0';
	__revert(beginning);
	
	return buffer;
}
