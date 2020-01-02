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

#include "uart.h"
#include <kernel/ddm.h>
#include <stdlib.h>
#include "../ports/ports.h"
#include "../../arch/i386/isr.h"

int write_handler(void * base, char * data, unsigned int size) {
	int written = 0;
	
	while (written < size) {
		dev_port_byte_out((unsigned short)base, *(data + written));
		written++;
	}
	
	return written;
}

int read_handler(void * base, char * buffer, int max) {
	int read = 0;
	
	for (; read < max; read++) {
		if (dev_port_byte_in((unsigned short)base + 5) & 1 == 0) {
			break;
		}
		
		buffer[read] = dev_port_byte_in((unsigned short)base);
	}
	
	return read;
}

k_ddm_device_t * dev_uart_init(void * base, const char * device_id) {
	k_ddm_device_t * device = __malloc(sizeof(k_ddm_device_t));
	
	device->id = device_id;
	device->base = base;
	device->write_handler = write_handler;
	device->read_handler = read_handler;
	
	k_ddm_register(device);

	dev_port_byte_out((unsigned short)base + 1, 0x00); /* Disbale interrupts */
	dev_port_byte_out((unsigned short)base + 2, 0xC7);
	dev_port_byte_out((unsigned short)base + 4, 0x0B);
	
	return device;
}
