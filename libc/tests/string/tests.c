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
#include <cmocka.h>

#include "test_string.h"
#include "strerror.h"
#include "strstr.h"
#include "strspn.h"

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(strlen_test),
		cmocka_unit_test(strcmp_test),
		cmocka_unit_test(strncmp_test),
		cmocka_unit_test(strcat_test),
		cmocka_unit_test(strncat_test),
		cmocka_unit_test(strcpy_test),
		cmocka_unit_test(strncpy_test),
		cmocka_unit_test(strchr_test),
		cmocka_unit_test(strrchr_test),
		cmocka_unit_test(strpbrk_test),
		cmocka_unit_test(memcpy_test),
		cmocka_unit_test(memmove_test),
		cmocka_unit_test(memset_test),
		cmocka_unit_test(memcmp_test),
		cmocka_unit_test(memchr_test),
		
		cmocka_unit_test(strstr_test),
		cmocka_unit_test(strerror_test),
        
        cmocka_unit_test(strspn_test),
        cmocka_unit_test(strcspn_test),
	};
	
	return cmocka_run_group_tests(tests, NULL, NULL);
}
