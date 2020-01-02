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

#include "ctype.h"

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(test_isalnum),
		cmocka_unit_test(test_isalpha),
		cmocka_unit_test(test_isblank),
		cmocka_unit_test(test_iscntrl),
		cmocka_unit_test(test_isprint),
		cmocka_unit_test(test_isdigit),
		cmocka_unit_test(test_isxdigit),
		cmocka_unit_test(test_isspace),
		cmocka_unit_test(test_isgraph),
		cmocka_unit_test(test_ispunct),
		cmocka_unit_test(test_islower),
		cmocka_unit_test(test_isupper),
		cmocka_unit_test(test_tolower),
		cmocka_unit_test(test_toupper),
	};
	
	return cmocka_run_group_tests(tests, NULL, NULL);
}
