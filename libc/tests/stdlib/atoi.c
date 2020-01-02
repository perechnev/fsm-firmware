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

#include "atoi.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/stdlib.h"

void atoi_test_positive(void **state) {
	assert_int_equal(0, __atoi("0"));
	assert_int_equal(1, __atoi("1"));
	assert_int_equal(9, __atoi("9"));
	assert_int_equal(100, __atoi("100"));
	assert_int_equal(1023, __atoi("1023"));
}

void atoi_test_negative(void **state) {
	assert_int_equal(0, __atoi("-0"));
	assert_int_equal(-1, __atoi("-1"));
	assert_int_equal(-9, __atoi("-9"));
	assert_int_equal(-100, __atoi("-100"));
	assert_int_equal(-1023, __atoi("-1023"));
}

void atoi_test_invalid(void **state) {
	assert_int_equal(0, __atoi(""));
	assert_int_equal(0, __atoi("a123"));
	assert_int_equal(0, __atoi("12f"));
	assert_int_equal(0, __atoi("a 4"));
	assert_int_equal(0, __atoi("12-4"));
	assert_int_equal(0, __atoi("-12-4-"));
}

void atoi_test_overflow(void **state) {
	
}
