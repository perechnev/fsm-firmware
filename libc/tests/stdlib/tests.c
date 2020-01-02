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

#include "atof.h"
#include "atoi.h"
#include "atol.h"
#include "strtod.h"
#include "srand.h"
#include "qsort.h"
#include "bsearch.h"
#include "abs.h"
#include "labs.h"
#include "div.h"

#include "itoa.h"

int main(void) {
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(atof_test_positive),
		cmocka_unit_test(atof_test_negative),
		cmocka_unit_test(atof_test_invalid),
		cmocka_unit_test(atof_test_overflow),
		
		cmocka_unit_test(atoi_test_positive),
		cmocka_unit_test(atoi_test_negative),
		cmocka_unit_test(atoi_test_invalid),
		cmocka_unit_test(atoi_test_overflow),
		
		cmocka_unit_test(atol_test_positive),
		cmocka_unit_test(atol_test_negative),
		cmocka_unit_test(atol_test_invalid),
		cmocka_unit_test(atol_test_overflow),
		
		cmocka_unit_test(srand_test_context),
		
		cmocka_unit_test(qsort_test_empty),
		cmocka_unit_test(qsort_test_one_member),
		cmocka_unit_test(qsort_test_two_members),
		cmocka_unit_test(qsort_test_char),
		cmocka_unit_test(qsort_test_int),
		
		cmocka_unit_test(bsearch_test_empty),
		cmocka_unit_test(bsearch_test_one_member),
		cmocka_unit_test(bsearch_test_two_members),
		cmocka_unit_test(bsearch_test_char),
		cmocka_unit_test(bsearch_test_int),
		
		cmocka_unit_test(abs_test_positive),
		cmocka_unit_test(abs_test_negative),
		
		cmocka_unit_test(labs_test_positive),
		cmocka_unit_test(labs_test_negative),
		
		cmocka_unit_test(div_test),
		cmocka_unit_test(ldiv_test),
		
		cmocka_unit_test(itoa_test_dec),
		cmocka_unit_test(itoa_test_hex),
		cmocka_unit_test(itoa_test_bin),
	};
	
	return cmocka_run_group_tests(tests, NULL, NULL);
}
