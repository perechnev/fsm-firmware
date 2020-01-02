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

#include "qsort.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../../include/stdlib.h"

int qsort_test_char_cmp(const void * l_ptr, const void * r_ptr) {
	return *((char *)l_ptr) - *((char *)r_ptr);
}

int qsort_test_int_cmp(const void * l_ptr, const void * r_ptr) {
	return *((int *)l_ptr) - *((int *)r_ptr);
}

void qsort_test_empty(void **state) {
	char a[] = "";
	
	__qsort(a, strlen(a), sizeof(char), qsort_test_char_cmp);
	assert_string_equal(a, "");
}

void qsort_test_one_member(void **state) {
	char a[] = "a";
	
	__qsort(a, strlen(a), sizeof(char), qsort_test_char_cmp);
	assert_string_equal(a, "a");
}

void qsort_test_two_members(void **state) {
	char a[] = "ba";
	
	__qsort(a, strlen(a), sizeof(char), qsort_test_char_cmp);
	assert_string_equal(a, "ab");
	
	__qsort(a, strlen(a), sizeof(char), qsort_test_char_cmp);
	assert_string_equal(a, "ab");
}

void qsort_test_int(void **state) {
	int a[] = { 100003, 100005, 100002, 100007, 100009, 100000, 100001, 100004, 100006, 100008 };
	int e[] = { 100000, 100001, 100002, 100003, 100004, 100005, 100006, 100007, 100008, 100009 };
	
	__qsort(a, 10, sizeof(int), qsort_test_int_cmp);
	
	for (int i = 0; i < 10; i++) {
		assert_int_equal(a[i], e[i]);
	}
}

void qsort_test_char(void **state) {
	char a[] = "qazwsxedcrfvtgbyhnujmikolp";
	
	__qsort(a, strlen(a), sizeof(char), qsort_test_char_cmp);
	assert_string_equal(a, "abcdefghijklmnopqrstuvwxyz");
}
