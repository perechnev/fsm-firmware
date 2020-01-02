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

#include "pl111.h"
#include <stdlib.h>

typedef struct {
	uint32_t	TIMING0; // Horizontal Axis Panel Control Register
	uint32_t	TIMING1; // Vertical Axis Panel Control Register
	uint32_t	TIMING2; // Clock and Signal Polarity Control Register
	uint32_t	TIMING3; // Line End Control Register
	uint32_t	UP_BASE;
	uint32_t	LP_BASE;
	uint32_t	CONTROL;
	uint32_t	IMSC;
	const uint32_t	RIS;
	const uint32_t	MIS;
	uint32_t	ICR;
	const uint32_t	UP_CURR;
	const uint32_t	LP_CURR;
	uint8_t 	RESERVED[0x1C8];
	uint8_t		PALETTE[0x1FC];
	const uint32_t	PERIPHID0;
	const uint32_t	PERIPHID1;
	const uint32_t	PERIPHID2;
	const uint32_t	PERIPHID3;
	const uint32_t	PCELLID0;
	const uint32_t	PCELLID1;
	const uint32_t	PCELLID2;
	const uint32_t	PCELLID3;
} dev_pl111_t;

k_ddm_device_t * dev_pl111_init(void * base, const char * device_id, uint32_t control) {
	k_ddm_device_t * device = malloc(sizeof(k_ddm_device_t));

	device->id = device_id;
	device->base = base;
	device->write_handler = NULL;
	device->read_handler = NULL;

	k_ddm_register(device);

	dev_pl111_t * display = base;

//	*(volatile unsigned int *)(0x1000001C) = 0x2CAC; /* timing magic for SVGA 800x600 */

	display->TIMING0 = 0x1313A4C4;
	display->TIMING1 = 0x0505F657;
	display->TIMING2 = 0x071F1800;
	display->UP_BASE = malloc(800 * 600 * sizeof(uint32_t));
	display->CONTROL = control;

	return device;
}

uint32_t * dev_pl111_fb_get(k_ddm_device_t * device) {
	dev_pl111_t * display = (dev_pl111_t *)device->base;
	if (display == NULL) {
		return NULL;
	}

	return (uint32_t *)display->UP_BASE;
}
