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

#include "PL03x.h"
#include <stdlib.h>

typedef struct {
	const uint32_t	DR;		// Data Register
	uint32_t		MR;		// Match Register
	uint32_t		LR;		// Load Register
	uint32_t		CR;		// Control Register
	uint32_t		IMSC;	// Interrupt Mask Set or Clear Register
	const uint32_t	RIS;	// Raw Interrupt Register
	const uint32_t	MIS;	// Masked Interrupt Register
	uint32_t		ICR;	// Interrupt Clear Register
} dev_PL03x_t;

k_ddm_device_t * dev_PL03x_init(void * base, const char * device_id) {
	k_ddm_device_t * device = malloc(sizeof(k_ddm_device_t));

	device->id = device_id;
	device->base = base;
	device->write_handler = NULL;
	device->read_handler = NULL;

	k_ddm_register(device);

	dev_PL03x_t * timer = (dev_PL03x_t *)base;
	timer->CR = PL03x_RTCCR_EN;

	return device;
}

uint32_t dev_PL03x_get(k_ddm_device_t * device) {
	dev_PL03x_t * timer = (dev_PL03x_t *)device->base;
	return timer->DR;
}
