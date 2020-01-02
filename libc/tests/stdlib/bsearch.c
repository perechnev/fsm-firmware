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

int bsearch_test_char_cmp(const void * l_ptr, const void * r_ptr) {
	return *((char *)l_ptr) - *((char *)r_ptr);
}

int bsearch_test_int_cmp(const void * l_ptr, const void * r_ptr) {
	return *((int *)l_ptr) - *((int *)r_ptr);
}

void bsearch_test_empty(void **state) {
	char a[] = "";
	char * result;
	char ch = 'a';
	
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result == __NULL);
}

void bsearch_test_one_member(void **state) {
	char a[] = "a";
	char * result;
	char ch;
	
	ch = 'a';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result != __NULL);
	assert_true(result != &ch);
	assert_true(*result == ch);
	
	ch = 'b';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result == __NULL);
}

void bsearch_test_two_members(void **state) {
	char a[] = "ab";
	char * result;
	char ch;
	
	ch = 'a';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result != __NULL);
	assert_true(result != &ch);
	assert_true(*result == ch);
	
	ch = 'b';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result != __NULL);
	assert_true(result != &ch);
	assert_true(*result == ch);
	
	ch = 'c';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result == __NULL);
}

void bsearch_test_int(void **state) {
	int a[] = { 100000, 100001, 100002, 100003, 100004, 100005, 100006, 100007, 100008, 100009 };
	int * result;
	int e;
	
	
	for (int i = 0; i < 10; i++) {
		e = a[i];
		result = __bsearch(&e, a, 10, sizeof(int), bsearch_test_int_cmp);
		assert_true(result != __NULL);
		assert_true(result != &e);
		assert_true(*result == e);
	}
	
	e = 10;
	result = __bsearch(&e, a, 10, sizeof(int), bsearch_test_int_cmp);
	assert_true(result == __NULL);
}

void bsearch_test_char(void **state) {
	char a[] = "abcdefghijklmnopqrstuvwxyz";
	char * result;
	char ch;
	
	for (int i = 0; i < strlen(a); i++) {
		ch = a[i];
		result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
		assert_true(result != __NULL);
		assert_true(result != &ch);
		assert_true(*result == ch);
	}
	
	ch = '-';
	result = __bsearch(&ch, a, strlen(a), sizeof(char), bsearch_test_char_cmp);
	assert_true(result == __NULL);
}
