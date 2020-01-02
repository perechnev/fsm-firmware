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

#ifndef __LIMITS_H__
#define __LIMITS_H__

#define __CHAR_BIT	8

#define __SCHAR_MIN	-128
#define __SCHAR_MAX	+127

#define __CHAR_MIN	-128
#define __CHAR_MAX	+127
#define __UCHAR_MAX	+255

#define	__MB_LEN_MAX	1

#define __SHRT_MIN	-32768
#define __SHRT_MAX	+32767
#define __USHRT_MAX	+65535

#define __INT_MIN	-2147483648
#define __INT_MAX	+2147483647
#define __UINT_MAX	+4294967295

#define __LONG_MIN	-2147483648
#define __LONG_MAX	+2147483647
#define __ULONG_MAX	+4294967295

#define __LLONG_MIN		-9223372036854775808
#define __LLONG_MAX		+9223372036854775807
#define __ULLONG_MAX	+18446744073709551615

#ifdef __LP64__
#define __LONG_MIN	-9223372036854775808
#define __LONG_MAX	+9223372036854775807
#define __ULONG_MAX	+18446744073709551615
#endif /* __LP64__ */

#if __STDC_HOSTED__ == 0

#define CHAR_BIT	__CHAR_BIT

#define SCHAR_MIN	__SCHAR_MIN
#define SCHAR_MAX	__SCHAR_MAX

#define CHAR_MIN	__CHAR_MIN
#define CHAR_MAX	__CHAR_MAX
#define UCHAR_MAX	__UCHAR_MAX

#define	MB_LEN_MAX	__MB_LEN_MAX

#define SHRT_MIN	__SHRT_MIN
#define SHRT_MAX	__SHRT_MAX
#define USHRT_MAX	__USHRT_MAX

#define INT_MIN		__INT_MIN
#define INT_MAX		__INT_MAX
#define UINT_MAX	__UINT_MAX

#define LONG_MIN	__LONG_MIN
#define LONG_MAX	__LONG_MAX
#define ULONG_MAX	__ULONG_MAX

#define LLONG_MIN	__LLONG_MIN
#define LLONG_MAX	__LLONG_MAX
#define ULLONG_MAX	__ULLONG_MAX

#endif /* __STDC_HOSTED__ */

#endif /* __LIMITS_H__ */

