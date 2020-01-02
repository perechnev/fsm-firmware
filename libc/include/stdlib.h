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

#ifndef __STDLIB_H__
#define __STDLIB_H__

#include "stddef.h"

typedef struct {
	int quot, rem;
} __div_t;

typedef struct {
	long int quot, rem;
} __ldiv_t;

typedef int (* __f_compar_t) (const void *, const void *);

double	__atof	(const char *__nptr);
int		__atoi	(const char *__nptr);
long	__atol	(const char *__nptr);

/*double			__strtod	(const char *__nptr, char **__endptr);*/
/*long			__strtol	(const char *__nptr, char **__endptr, int __base);
unsigned long	__strtoul	(const char *__nptr, char **__endptr, int __base);*/

int		__rand	(void);
void	__srand	(unsigned int __seed);

void *	__malloc	(__size_t __size);
void *	__realloc	(void *__ptr, __size_t __size);
void	__free		(void *__ptr);
/* void *	__calloc	(__size_t __nmemb, __size_t __size);
 * void		__abort	(void);
 * int		__atexit(void (*__func) (void));
 * void		__exit(int __status);
 * char *	__getenv(const char *__name);
 * int		__system(const char *__command);
 */

void * __bsearch(
	const void *__key,
	const void *__base,
	__size_t __nmemb,
	__size_t __size,
	__f_compar_t __compar
);

void __qsort(
	void *__base,
	__size_t __nmemb,
	__size_t __size,
	__f_compar_t __compar
);

int			__abs	(int __x);
long int	__labs	(long int __x);
__div_t		__div	(int __number, int __denom);
__ldiv_t	__ldiv	(long int __number, long int __denom);

/*
 * Functions that are not in C89 standard.
 */

void *	__itoa	(int input, char * buffer, int radix);

#define	div_t	__div_t
#define	ldiv_t	__ldiv_t

#define	f_compar_t	__f_compar_t

#define	atof	__atof
#define	atoi	__atoi
#define	atol	__atol

#define	rand	__rand
#define	srand	__srand

#define	malloc	__malloc
#define realloc	__realloc
#define	free	__free

#define	bsearch	__bsearch
#define	qsort	__qsort

#define	abd		__abs
#define	labs	__labs
#define	div		__div
#define	ldiv	__ldiv
#define	itoa	__itoa

#endif /* __STDLIB_H__ */
