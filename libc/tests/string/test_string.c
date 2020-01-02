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
#include <string.h>
#include <setjmp.h>
#include <stdio.h>
#include <cmocka.h>
#include "../../include/string.h"
#include "../../include/stddef.h"

void strlen_test(void **state) {
	assert_true(5 == __strlen("Hello"));
	assert_true(8 == __strlen("Good bye"));
	assert_true(0 == __strlen(""));
}

void strcmp_test(void **state) {
	assert_true( 0 == __strcmp("abcde", "abcde"));
	assert_true(-1 == __strcmp("abcdd", "abcde"));
	assert_true( 1 == __strcmp("abcde", "abcdd"));
	assert_true( 1 == __strcmp("abcde", "abcd" ));
	assert_true(-1 == __strcmp("abcd",  "abcde"));
}

void strncmp_test(void **state) {
	assert_true( 0 == __strncmp("aaa", "bbb", 0));
	assert_true( 0 == __strncmp("abcde", "abcde", 5));
	assert_true( 0 == __strncmp("abcde", "abcde", 10));
	assert_true(-1 == __strncmp("abcde", "abcdeabcde", 10));
	assert_true( 1 == __strncmp("abcdeabcde", "abcde", 10));
	assert_true( 0 == __strncmp("abcdd", "abcee", 3));
	assert_true(-1 == __strncmp("abccc", "abddd", 3));
	assert_true(-1 == __strncmp("abccc", "abddd", 5));
	assert_true( 1 == __strncmp("abddd", "abccc", 3));
	assert_true( 1 == __strncmp("abddd", "abccc", 5));
}

void strcat_test(void **state) {
	char dst[32];
	char src[32];
	char * result = NULL;
	
	memset(dst, 'A', 32);
	memset(src, 'B', 32);
	
	strcpy(dst, "Hello");
	strcpy(src, " world!");
	result = __strcat(dst, src);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "Hello world!"));
	
	strcpy(dst, "");
	strcpy(src, "ololo");
	result = __strcat(dst, src);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "ololo"));
	
	strcpy(dst, "test");
	strcpy(src, "");
	result = __strcat(dst, src);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "test"));
	
	strcpy(dst, "");
	strcpy(src, "");
	result = __strcat(dst, src);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, ""));
}

void strncat_test(void **state) {
	char dst[32];
	char src[32];
	char * result = NULL;
	
	memset(dst, 'A', 32);
	memset(src, 'B', 32);
	
	strcpy(dst, "Hello");
	strcpy(src, " world!");
	result = __strncat(dst, src, strlen(src));
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "Hello world!"));
	
	strcpy(dst, "Hello");
	strcpy(src, " world!");
	result = __strncat(dst, src, 0);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "Hello"));
	
	strcpy(dst, "Hello");
	strcpy(src, " world!");
	result = __strncat(dst, src, 1);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "Hello "));
	
	strcpy(dst, "");
	strcpy(src, "ololo");
	result = __strncat(dst, src, 3);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "olo"));
	
	strcpy(dst, "test");
	strcpy(src, "");
	result = __strncat(dst, src, 5);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, "test"));
	
	strcpy(dst, "");
	strcpy(src, "");
	result = __strncat(dst, src, 3);
	assert_true(dst == result);
	assert_true(0 == strcmp(dst, ""));
}

void strcpy_test(void **state) {
	#define STRING_SIZE 32
	
	char dst[STRING_SIZE];
	char src[STRING_SIZE];
	char * result = NULL;
	
	memset(dst, 'A', STRING_SIZE);
	memset(src, 'B', STRING_SIZE);
	
	strcpy(dst, "test");
	strcpy(src, "string");
	result = __strcpy(dst, src);
	assert_true(result == dst);
	assert_true(0 == strcmp(dst, "string"));
	
	strcpy(dst, "test");
	strcpy(src, "");
	result = __strcpy(dst, src);
	assert_true(result == dst);
	assert_true(0 == strcmp(dst, ""));
	
	strcpy(dst, "");
	strcpy(src, "string");
	result = __strcpy(dst, src);
	assert_true(result == dst);
	assert_true(0 == strcmp(dst, "string"));
	
	strcpy(dst, "");
	strcpy(src, "");
	result = __strcpy(dst, src);
	assert_true(result == dst);
	assert_true(0 == strcmp(dst, ""));
}

void strncpy_test(void **state) {
	#define STRING_SIZE 32
	
	char dst[STRING_SIZE];
	char src[STRING_SIZE];
	char * result = NULL;
	
	memset(dst, 'A', STRING_SIZE);
	memset(src, 'B', STRING_SIZE);
	
	strcpy(dst, "test");
	strcpy(src, " string");
	result = __strncpy(dst, src, strlen(src));
	assert_ptr_equal(dst, result);
	assert_string_equal(dst, "test string");
	
	strcpy(dst, "test");
	strcpy(src, " string");
	result = __strncpy(dst, src, 2);
	assert_ptr_equal(dst, result);
	assert_string_equal(dst, "test s");
	
	strcpy(dst, "");
	strcpy(src, " string");
	result = __strncpy(dst, src, strlen(src));
	assert_ptr_equal(dst, result);
	assert_string_equal(dst, " string");
	
	strcpy(dst, "test");
	strcpy(src, "");
	result = __strncpy(dst, src, strlen(src));
	assert_ptr_equal(dst, result);
	assert_string_equal(dst, "test");
	
	strcpy(dst, "");
	strcpy(src, "");
	result = __strncpy(dst, src, strlen(src));
	assert_ptr_equal(dst, result);
	assert_string_equal(dst, "");
}

void strchr_test(void **state) {
	char s[] = "abcdefgh";
	char * result;
	
	result = __strchr(s, 'd');
	assert_ptr_equal(result, s + 3);
	
	result = __strchr(s, 'z');
	assert_ptr_equal(result, __NULL);
	
	strcpy(s, "abcdeeee");
	result = __strchr(s, 'e');
	assert_ptr_equal(result, s + 4);
	
	strcpy(s, "");
	result = __strchr(s, 'a');
	assert_ptr_equal(result, __NULL);
}

void strrchr_test(void **state) {
	char s[] = "abcdefgh";
	char * result;
	
	result = __strrchr(s, 'd');
	assert_ptr_equal(result, s + 3);
	
	result = __strrchr(s, 'a');
	assert_ptr_equal(result, s);
	
	result = __strrchr(s, 'z');
	assert_ptr_equal(result, __NULL);
	
	strcpy(s, "abcdeeee");
	result = __strrchr(s, 'e');
	assert_ptr_equal(result, s + 7);
	
	strcpy(s, "");
	result = __strrchr(s, 'a');
	assert_ptr_equal(result, __NULL);
}

void strpbrk_test(void **state) {
	char s[] = "abcdefgh";
	char * result = NULL;
	
	result = __strpbrk(s, "dfg");
	assert_ptr_equal(result, s + 3);
	
	result = __strpbrk(s, "gfd");
	assert_ptr_equal(result, s + 3);
	
	result = __strpbrk(s, "");
	assert_ptr_equal(result, __NULL);
	
	result = __strpbrk("", "abc");
	assert_ptr_equal(result, __NULL);
	
	result = __strpbrk("", "");
	assert_ptr_equal(result, __NULL);
}

void memcpy_test(void **state) {
	__uint8_t src[] = { 0x01, 0x01, 0x01, 0x01, 0x01 };
	__uint8_t dst[] = { 0x00, 0x00, 0x00, 0x00, 0x00 };
	
	assert_true(dst == (__uint8_t *)__memcpy(dst, src, 2));
	assert_true(dst[0] == 0x01);
	assert_true(dst[1] == 0x01);
	assert_true(dst[2] == 0x00);
	assert_true(dst[3] == 0x00);
	assert_true(dst[4] == 0x00);
	
	__memcpy(dst, src, 0);
	assert_true(dst[0] == 0x01);
	assert_true(dst[1] == 0x01);
}

void memmove_test(void **state) {
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	char * result = NULL;
	
	result = __memmove(arr + 5, "abcde", 5);
	assert_ptr_equal(arr + 5, result);
	assert_string_equal(arr, "abcdeabcdeklmnopqrstuvwxyz");
	
	result = __memmove(arr, arr + 1, 5);
	assert_ptr_equal(arr, result);
	assert_string_equal(arr, "bcdeaabcdeklmnopqrstuvwxyz");
	
	strcpy(arr, "abcdefghijklmnopqrstuvwxyz");
	result = __memmove(arr + 1, arr, 5);
	assert_ptr_equal(arr + 1, result);
	assert_string_equal(arr, "aabcdeghijklmnopqrstuvwxyz");
	
	strcpy(arr, "abcdefghijklmnopqrstuvwxyz");
	result = __memmove(arr, arr, 20);
	assert_ptr_equal(arr, result);
	assert_string_equal(arr, "abcdefghijklmnopqrstuvwxyz");
}

void memset_test(void **state) {
	char test_string[] = "aaaaa";
	
	char *returned_string = (char *)__memset(test_string, 'q', 2);
	assert_true(test_string == returned_string);
	assert_true('q' == test_string[0]);
	assert_true('q' == test_string[1]);
	assert_true('a' == test_string[2]);
	assert_true('a' == test_string[3]);
	assert_true('a' == test_string[4]);
	
	__memset(test_string, ' ', 0);
	assert_true('q' == test_string[0]);
	assert_true('q' == test_string[1]);
}

void memcmp_test(void **state) {
	const char a1[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
	const char a2[] = { 0x01, 0x02, 0x03, 0x03, 0x03 };
	const char a3[] = { 0x02, 0x03, 0x04, 0x05, 0x06 };
	
	assert_true( 0 == __memcmp(a1, a3, 0));
	assert_true( 0 == __memcmp(a1, a2, 3));
	assert_true( 1 == __memcmp(a1, a2, 5));
	assert_true(-1 == __memcmp(a1, a3, 5));
}

void memchr_test(void **state) {
	char s[] = "abcdefgh";
	char * result;
	
	result = __memchr(s, 'd', 8);
	assert_ptr_equal(result, s + 3);
	
	result = __memchr(s, 'd', 3);
	assert_ptr_equal(result, __NULL);
	
	strcpy(s, "abcddddd");
	result = __memchr(s, 'd', 8);
	assert_ptr_equal(result, s + 3);
	
	result = __memchr(s, 'z', 8);
	assert_ptr_equal(result, __NULL);
}
