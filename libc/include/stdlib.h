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
} div_t;

typedef struct {
	long int quot, rem;
} ldiv_t;

typedef int (* f_compar_t) (const void *, const void *);

double	atof	(const char * nptr);
int		atoi	(const char * nptr);
long	atol	(const char * nptr);

/*double			__strtod	(const char *__nptr, char **__endptr);*/
/*long			__strtol	(const char *__nptr, char **__endptr, int __base);
unsigned long	__strtoul	(const char *__nptr, char **__endptr, int __base);*/

int		rand	(void);
void	srand	(unsigned int seed);

void *	malloc	(size_t size);
void *	realloc	(void * ptr, size_t size);
void	free	(void * ptr);
void *  calloc  (size_t nmemb, size_t size);
/* void		__abort	(void);
 * int		__atexit(void (*__func) (void));
 * void		__exit(int __status);
 * char *	__getenv(const char *__name);
 * int		__system(const char *__command);
 */

void * bsearch(const void * key, const void * base, size_t nmemb, size_t size, f_compar_t compar);

void qsort(void * base, size_t nmemb, size_t size, f_compar_t compar);

int			abs	(int x);
long int    labs(long int x);
div_t		div (int number, int denom);
ldiv_t	    ldiv(long int number, long int denom);

/*
 * Functions that are not in C89 standard.
 */

void *	itoa(int input, char * buffer, int radix);

#endif /* __STDLIB_H__ */
