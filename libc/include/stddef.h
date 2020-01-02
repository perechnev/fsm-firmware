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

#ifndef __STDDEF_H__
#define __STDDEF_H__

#ifndef __NULL
#define __NULL ((void *)0)
#endif

#define __offsetof( st, m ) __builtin_offsetof( st, m )

typedef unsigned int __size_t;
typedef int     __ptrdiff_t;
typedef char    __wchar_t;

#if __STDC_HOSTED__ == 0

#define	NULL		__NULL
#define	offsetof	__offsetof
#define	size_t		__size_t
#define	ptrdiff_t	__ptrdiff_t
#define	wchar_t		__wchar_t

#endif /* __STDC_HOSTED__ */

#endif /* __STDDEF_H__ */
