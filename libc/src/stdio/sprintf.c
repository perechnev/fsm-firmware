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
#include <stdarg.h>

int sprintf(char * s, const char * format, ...) {
	char replacing = 0;
	char buffer[64];
	char *buffer_ptr = buffer;
	
	__va_list args;
	__va_start(args, format);
	
	do {
		if (replacing == 1) {
			if (*format == 's') {
				char *c = __va_arg(args, char *);
				
				while (*c != '\0') {
					*s = *c;
					s++;
					c++;
				}
			} else if (*format == 'd') {
				int n = __va_arg(args, int);
				
				itoa(n, buffer, 10);
				buffer_ptr = buffer;
				while (*buffer_ptr != '\0') {
					*s = *buffer_ptr;
					s++;
					buffer_ptr++;
				}
			}
			replacing = 0;
		} else if (*format == '%') {
			replacing = 1;
		} else {
			*s = *format;
			s++;
		}
		
		format++;
	}
	while (*format != '\0');
	
	__va_end(args);
	
	*s = '\0';
	return 0;
}
