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

#ifndef __STRING_H__
#define __STRING_H__

#include "stddef.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

int		memcmp	(const char * s1, const char * s2, size_t n);
void *	memcpy	(void * dest, const void * src, size_t n);
void *	memmove	(void * dest, const void * src, size_t n);
void *	memchr	(const char * s, int c, size_t n);
void *	memset	(void * s, int c, size_t n);

int		strcmp	(const char * s1, const char * s2);
int		strncmp	(const char * s1, const char * s2, size_t n);
char *	strcat	(char * dest, const char * src);
char *	strncat	(char * dest, const char * src, size_t n);
char *	strchr	(const char * s, int c);
char *	strrchr	(const char * s, int c);
char *	strcpy	(char * dest, const char * src);
char *	strncpy	(char * dest, const char * src, size_t n);
char *	strerror	(int errnum);
char *	strpbrk	(const char * s, const char * accept);
char *  strstr	(const char * haystack, const char * needle);
char *	strtok	(char * s, const char * delim);
size_t	strlen	(const char * s);
size_t	strspn	(const char * s, const char * accept);
size_t	strcspn	(const char * s, const char * reject);

/* 
 * Depends on locale, so it will not be implemented yet.
 * int		__strcoll	(const char * __s1, const char * __s2);
 * __size_t	__strxfrm	(char * __dest, const char * __src, __size_t __n);
 */

#endif /* __STRING_H__ */
