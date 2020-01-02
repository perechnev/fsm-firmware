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

#ifndef __STDINT_H__
#define __STDINT_H__

typedef	char		__int8_t;
typedef short		__int16_t;
typedef	int			__int32_t;

typedef unsigned char		__uint8_t;
typedef unsigned short		__uint16_t;
typedef unsigned int		__uint32_t;

#if __STDC_HOSTED__ == 0

#define	int8_t		__int8_t
#define	int16_t		__int16_t
#define int32_t		__int32_t
#define	uint8_t		__uint8_t
#define	uint16_t	__uint16_t
#define	uint32_t	__uint32_t

#endif /* __STDC_HOSTED__ */

#endif /* __STDINT_H__ */
