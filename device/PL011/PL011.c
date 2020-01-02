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

#include "PL011.h"
#include <stdlib.h>

int write_handler(void * base, char * data, unsigned int size) {
	PL011_t *base_ptr = (PL011_t *)base;
	int written = 0;
	
	while (written < size) {
		while (base_ptr->FR.TXFF != 0);
		base_ptr->DR.DATA = *(data + written);
		written++;
	}
	
	return written;
}

int read_handler(void * base, char * buffer, int max) {
	PL011_t *base_ptr = (PL011_t *)base;
	int i = 0;
	
	for (; i < max; i++) {
		if (base_ptr->FR.RXFE != 0) {
			break;
		}
		
		buffer[i] = base_ptr->DR.DATA;
	}
	
	return i;
}

k_ddm_device_t * dev_pl011_init(void * base, const char * device_id) {
	k_ddm_device_t * device = malloc(sizeof(k_ddm_device_t));
	
	device->id = device_id;
	device->base = base;
	device->write_handler = write_handler;
	device->read_handler = read_handler;
	
	k_ddm_register(device);
	
	return device;
}

