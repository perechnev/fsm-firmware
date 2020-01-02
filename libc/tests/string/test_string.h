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

#ifndef __TEST_STRING_H__
#define __TEST_STRING_H__

void	strlen_test	(void **state);
void	strcmp_test	(void **state);
void	strncmp_test(void **state);
void	strcat_test	(void **state);
void	strncat_test(void **state);
void	strcpy_test	(void **state);
void	strncpy_test(void **state);
void	strchr_test	(void **state);
void	strrchr_test(void **state);
void	strpbrk_test(void **state);
void	memcpy_test	(void **state);
void	memmove_test(void **state);
void	memset_test	(void **state);
void	memcmp_test	(void **state);
void	memchr_test	(void **state);

#endif
