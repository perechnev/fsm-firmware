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

double __atof(const char * __nptr) {
	double value = 0.0;
	double sign = 1.0;
	char digit;
	float after_dot = 0.0;
	
	if (*__nptr == '-') {
		sign = -1.0;
		__nptr++;
	}
	
	while (*__nptr != '\0') {
		if (*__nptr == '.' && after_dot == 0.0) {
			after_dot = 10.0;
			__nptr++;
			continue;
		}
		
		digit = *__nptr - '0';
		__nptr++;
			
		if (digit < 0 || digit > 9) {
			return -0.0;
		}
		
		if (after_dot > 0.0) {
			value += (double)digit / after_dot;
			after_dot *= 10.0;
		} else {
			value *= 10.0;
			value += (double)digit;
		}
	}
	
	return value * sign;
}
