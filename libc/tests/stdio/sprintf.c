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

#include "sprintf.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/stdio.h"

void sprintf_test_empty(void **state) {
	char buffer[256];
	
	__sprintf(buffer, "");
	assert_string_equal(buffer, "");
	
	__sprintf(buffer, "Hello world!");
	assert_string_equal(buffer, "Hello world!");
}

void sprintf_test_string(void **state) {
	char buffer[256];
	
	__sprintf(buffer, "Hello %s", "world!");
	assert_string_equal(buffer, "Hello world!");
	
	__sprintf(buffer, "Hello %s again from %s!", "world", "Alex");
	assert_string_equal(buffer, "Hello world again from Alex!");
}

void sprintf_test_decimal(void **state) {
	char buffer[256];
	
	__sprintf(buffer, "I'm %d years old.", 27);
	assert_string_equal(buffer, "I'm 27 years old.");
	
	__sprintf(buffer, "I'm %d years old. My dog is %d.", 27, 5);
	assert_string_equal(buffer, "I'm 27 years old. My dog is 5.");
}
