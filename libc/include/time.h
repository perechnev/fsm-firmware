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

#ifndef __TIME_H__
#define __TIME_H__

#define __CLOCKS_PER_SEC	0 /* ! */
#define	__CLK_PER_SEC		0 /* ! */

typedef int __clock_t;
typedef int __time_t;

struct __tm {
		int	tm_sec;
		int	tm_min;
		int	tm_hour;
		int	tm_mday;
		int	tm_mon;
		int tm_year;
		int tm_wday;
		int tm_yday;
		int tm_isdst;
};

__clock_t	__clock	(void);
__time_t	__time	(__time_t *__tp);
double		__difftime	(__time_t __time2, __time_t __time1);
__time_t	__mktime	(struct __tm *__tp);
/* char *		__asctime	(const struct __tm *__tp); */

#if __STDC_HOSTED__ == 0

#define CLOCKS_PER_SEC	__CLOCKS_PER_SEC
#define	CLK_PER_SEC		__CLK_PER_SEC

#define	clock_t	__clock_t
#define	time_t	__time_t

#define	tm		__tm

#define	clock		__clock
#define	time		__time
#define	difftime	__difftime
#define	mktime		__mktime

#endif /* __STDC_HOSTED__ */

#endif /* __TIME_H__ */
