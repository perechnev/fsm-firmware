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

#ifndef __DRIVER_PL011_h__
#define __DRIVER_PL011_h__

#include <stdint.h>
#include <kernel/ddm.h>

typedef struct {
	struct {
		int8_t	DATA;
		uint8_t	FLAGS;
		uint16_t	reserved;
	} DR;
	uint32_t	RSR_ECR;
	uint32_t	reserved_a[4];
	struct {
		uint32_t	CTS		: 1;
		uint32_t	DSR		: 1;
		uint32_t	DCD		: 1;
		uint32_t	BUSY	: 1;
		uint32_t	RXFE	: 1;
		uint32_t	TXFF	: 1;
		uint32_t	TXFE	: 1;
		uint32_t	RI		: 1;
	} FR;
	uint32_t	reserved_b;
	uint32_t	ILPR;
	uint32_t	IBRD;
	uint32_t	FBRD;
	uint32_t	LCRH;
	uint32_t	CR;
	uint32_t	IFLS;
	uint32_t	IMSC;
	uint32_t	RIS;
	uint32_t	MIS;
	uint32_t	ICR;
} PL011_t;

k_ddm_device_t * dev_pl011_init(void * base, const char * device_id);

#endif /* __DRIVER_PL011_h__ */
