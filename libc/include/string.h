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

#ifndef __NULL
#define __NULL ((void *)0)
#endif

int		__memcmp	(const char * __s1, const char * __s2, __size_t __n);
void *	__memcpy	(void * __dest, const void * __src, __size_t __n);
void *	__memmove	(void * __dest, const void * __src, __size_t __n);
void *	__memchr	(const char * __s, int __c, __size_t __n);
void *	__memset	(void * __s, int __c, __size_t __n);

int		__strcmp	(const char * __s1, const char * __s2);
int		__strncmp	(const char * __s1, const char * __s2, __size_t __n);
char *	__strcat	(char * __dest, const char * __src);
char *	__strncat	(char * __dest, const char * __src, __size_t __n);
char *	__strchr	(const char * __s, int __c);
char *	__strrchr	(const char * __s, int __c);
char *	__strcpy	(char * __dest, const char * __src);
char *	__strncpy	(char * __dest, const char * __src, __size_t __n);
char *	__strerror	(int __errnum);
char *	__strpbrk	(const char * __s, const char * __accept);
char *	__strstr	(const char * __haystack, const char * __needle);
char *	__strtok	(char * __s, const char * __delim);
__size_t	__strlen	(const char * __s);
__size_t	__strspn	(const char * __s, const char * __accept);
__size_t	__strcspn	(const char * __s, const char * __reject);

/* 
 * Depends on locale, so it will not be implemented yet.
 * int		__strcoll	(const char * __s1, const char * __s2);
 * __size_t	__strxfrm	(char * __dest, const char * __src, __size_t __n);
 */

#if __STDC_HOSTED__ == 0

#define	NULL	__NULL

#define	memcmp	__memcmp
#define	memcpy	__memcpy
#define	memmove	__memmove
#define	memchr	__memchr
#define	memset	__memset

#define	strcmp		__strcmp
#define	strncmp		__strncmp
#define	strcat		__strcat
#define	strncat		__strncat
#define	strchr		__strchr
#define	strrchr		__strrchr
#define	strcpy		__strcpy
#define	strncpy		__strncpy
#define	strerror	__strerror
#define	strpbrk		__strpbrk
#define	strstr		__strstr
#define	strtok		__strtok
#define	strlen		__strlen
#define	strspn		__strspn
#define	strcspn		__strcspn

#endif /* __STDC_HOSTED__ */

#endif /* __STRING_H__ */
