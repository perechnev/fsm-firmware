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

#ifndef __CTYPE_H__
#define __CTYPE_H__

int		__isalnum	(int __c);
int		__isalpha	(int __c);
int		__isblank	(int __c);
int 	__iscntrl	(int __c);
int		__isdigit	(int __c);
int		__isgraph	(int __c);
int		__islower	(int __c);
int		__isprint	(int __c);
int 	__ispunct	(int __c);
int		__isspace	(int __c);
int		__isupper	(int __c);
int		__isxdigit	(int __c);

int		__tolower	(int __c);
int		__toupper	(int __c);

#define	isalnum		__isalnum
#define	isalpha		__isalpha
#define	isblank		__isblank
#define	iscntrl		__iscntrl
#define isdigit		__isdigit
#define	isgraph		__isgraph
#define	islower		__islower
#define	isprint		__isprint
#define	ispunct		__ispunct
#define	isspace		__isspace
#define	isupper		__isupper
#define	isxdigit	__isxdigit
#define	tolower		__tolower
#define	toupper		__toupper

#endif /* __CTYPE_H__ */
