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

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <cmocka.h>
#include "strstr.h"
#include "../../include/stddef.h"
#include "../../include/string.h"

void strstr_test(void **state) {
	char s[32];
	char *result = __NULL;
	
	strcpy(s, "abcdefghfgh");
	
	result = __strstr(s, "cde");
	assert_ptr_equal(result, s + 2);
	
	result = __strstr(s, "fgh");
	assert_ptr_equal(result, s + 5);
	
	strcpy(s, "");
	
	result = __strstr(s, "");
	assert_ptr_equal(result, s);
	
	result = __strstr("", "cde");
	assert_ptr_equal(result, __NULL);
	
	strcpy(s, "abcddddddddefgh");
	
	result = __strstr(s, "def");
	assert_ptr_equal(result, s + 10);
}

