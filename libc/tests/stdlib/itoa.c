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

#include "itoa.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/stdlib.h"

void itoa_test_dec(void **state) {
	const int BASE = 10;
	char buffer[32];
	
	__itoa(0, buffer, BASE);
	assert_string_equal("0", buffer);
	
	__itoa(1, buffer, BASE);
	assert_string_equal("1", buffer);
	
	__itoa(13, buffer, BASE);
	assert_string_equal("13", buffer);
	
	__itoa(14236, buffer, BASE);
	assert_string_equal("14236", buffer);
}

void itoa_test_hex(void **state) {
	const int BASE = 16;
	char buffer[32];
	
	__itoa(0, buffer, BASE);
	assert_string_equal("0x0", buffer);
	
	__itoa(1, buffer, BASE);
	assert_string_equal("0x1", buffer);
	
	__itoa(255, buffer, BASE);
	assert_string_equal("0xFF", buffer);
	
	__itoa(12345, buffer, BASE);
	assert_string_equal("0x3039", buffer);
}

void itoa_test_bin(void **state) {
	const int BASE = 2;
	char buffer[32];
	
	__itoa(0, buffer, BASE);
	assert_string_equal("0b0", buffer);
	
	__itoa(1, buffer, BASE);
	assert_string_equal("0b1", buffer);
	
	__itoa(5, buffer, BASE);
	assert_string_equal("0b101", buffer);
	
	__itoa(12, buffer, BASE);
	assert_string_equal("0b1100", buffer);
}
