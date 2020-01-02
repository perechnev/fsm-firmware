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

#include <kernel.h>
#include <ddm.h>

#define K_DDM_MAX_DEVICES	10

int devices = 0;
k_ddm_device_t * device_list[K_DDM_MAX_DEVICES];

int k_ddm_register(k_ddm_device_t * device) {
	if (devices == K_DDM_MAX_DEVICES) {
		return -1;
	}
	
	device_list[devices] = device;
	devices++;
	
	return devices;
}

k_ddm_device_t * k_ddm_get_device(char * device_id) {
	int i;
	k_ddm_device_t * device;
	
	for (i = 0; i < K_DDM_MAX_DEVICES; i++) {
		device = device_list[i];
		
		if (device->id[0] == device_id[0] && device->id[1] == device_id[1]) {
			return device;
		}
	}
	
	return K_NULL;
}

int k_ddm_write(k_ddm_device_t * device, char * data, unsigned int lenght) {
	k_ddm_write_handler_f handler = device->write_handler;
	if (handler == K_NULL) {
		return -1;
	}
	
	return handler(device->base, data, lenght);
}

int k_ddm_read(k_ddm_device_t * device, char * buffer, int max) {
	k_ddm_read_handler_f handler = device->read_handler;
	if (handler == K_NULL) {
		return 0;
	}
	
	return handler(device->base, buffer, max);
}
