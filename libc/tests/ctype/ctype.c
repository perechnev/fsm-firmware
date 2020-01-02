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

#include "ctype.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/ctype.h"

void test_isalnum(void **state) {
	assert_int_equal(1, __isalnum('A'));
	assert_int_equal(1, __isalnum('z'));
	assert_int_equal(1, __isalnum('6'));
	
	assert_int_equal(0, __isalnum(' '));
	assert_int_equal(0, __isalnum('#'));
}

void test_isalpha(void **state) {
	assert_int_equal(1, __isalpha('A'));
	assert_int_equal(1, __isalpha('b'));
	assert_int_equal(1, __isalpha('q'));
	assert_int_equal(1, __isalpha('Z'));
	
	assert_int_equal(0, __isalpha('1'));
	assert_int_equal(0, __isalpha('\0'));
	assert_int_equal(0, __isalpha(' '));
}

void test_isblank(void **state) {
	assert_int_equal(1, __isblank(' '));
	assert_int_equal(1, __isblank('\t'));
	
	assert_int_equal(0, __isblank('\n'));
	assert_int_equal(0, __isblank('\r'));
	assert_int_equal(0, __isblank('a'));
}

void test_iscntrl(void **state) {
	for (int c = 0x00; c <= 0x1f; c++) {
		assert_int_equal(1, __iscntrl(c));
	}
	
	for (int c = 0x20; c < 0x7f; c++) {
		assert_int_equal(0, __iscntrl(c));
	}
	
	assert_int_equal(1, __iscntrl(0x7f));
}

void test_isprint(void **state) {
	for (int c = 0x00; c <= 0x1f; c++) {
		assert_int_equal(0, __isprint(c));
	}
	
	for (int c = 0x20; c < 0x7f; c++) {
		assert_int_equal(1, __isprint(c));
	}
	
	assert_int_equal(0, __isprint(0x7f));
}

void test_isgraph(void **state) {
	for (int c = 0x00; c <= 0x1f; c++) {
		assert_int_equal(0, __isgraph(c));
	}
	
	assert_int_equal(0, __isgraph(' ')); /* 0x20 */
	
	for (int c = 0x21; c < 0x7f; c++) {
		assert_int_equal(1, __isgraph(c));
	}
	
	assert_int_equal(0, __isgraph(0x7f));
}

void test_ispunct(void **state) {
	// Not tests
}

void test_isdigit(void **state) {
	assert_int_equal(1, __isdigit('1'));
	assert_int_equal(1, __isdigit('5'));
	assert_int_equal(1, __isdigit('0'));
	
	assert_int_equal(0, __isdigit('a'));
	assert_int_equal(0, __isdigit('#'));
	assert_int_equal(0, __isdigit('/'));
}

void test_isxdigit(void **state) {
	assert_int_equal(1, __isxdigit('0'));
	assert_int_equal(1, __isxdigit('5'));
	assert_int_equal(1, __isxdigit('9'));
	assert_int_equal(1, __isxdigit('A'));
	assert_int_equal(1, __isxdigit('C'));
	assert_int_equal(1, __isxdigit('F'));
	assert_int_equal(1, __isxdigit('a'));
	
	assert_int_equal(0, __isxdigit('g'));
	assert_int_equal(0, __isxdigit('N'));
	assert_int_equal(0, __isxdigit('#'));
	assert_int_equal(0, __isxdigit('/'));
}

void test_isspace(void **state) {
	assert_int_equal(1, __isspace(' '));
	assert_int_equal(1, __isspace('\t'));
	assert_int_equal(1, __isspace('\n'));
	assert_int_equal(1, __isspace('\v'));
	assert_int_equal(1, __isspace('\f'));
	assert_int_equal(1, __isspace('\r'));
	
	assert_int_equal(0, __isspace(' ' - 1));
	assert_int_equal(0, __isspace(' ' + 1));
	
	assert_int_equal(0, __isspace('\t' - 1));
	assert_int_equal(0, __isspace('\r' + 1));
	
	assert_int_equal(0, __isspace('a'));
}

void test_islower(void **state) {
	assert_int_equal(0, __islower('A'));
	assert_int_equal(0, __islower('N'));
	assert_int_equal(0, __islower('Z'));
	
	assert_int_equal(1, __islower('a'));
	assert_int_equal(1, __islower('n'));
	assert_int_equal(1, __islower('z'));
	
	assert_int_equal(0, __islower(' '));
	assert_int_equal(0, __islower('1'));
	assert_int_equal(0, __islower('/'));
}

void test_isupper(void **state) {
	assert_int_equal(1, __isupper('A'));
	assert_int_equal(1, __isupper('N'));
	assert_int_equal(1, __isupper('Z'));
	
	assert_int_equal(0, __isupper('a'));
	assert_int_equal(0, __isupper('n'));
	assert_int_equal(0, __isupper('z'));
	
	assert_int_equal(0, __isupper(' '));
	assert_int_equal(0, __isupper('1'));
	assert_int_equal(0, __isupper('/'));
}

void test_tolower(void **state) {
	assert_int_equal('a', __tolower('A'));
	assert_int_equal('k', __tolower('K'));
	assert_int_equal('z', __tolower('Z'));
	
	assert_int_equal('a', __tolower('a'));
	assert_int_equal('#', __tolower('#'));
	assert_int_equal('4', __tolower('4'));
}

void test_toupper(void **state) {
	assert_int_equal('A', __toupper('a'));
	assert_int_equal('K', __toupper('k'));
	assert_int_equal('Z', __toupper('z'));
	
	assert_int_equal('A', __toupper('A'));
	assert_int_equal('#', __toupper('#'));
	assert_int_equal('4', __toupper('4'));
}
