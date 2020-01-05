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

#include <kernel/ddm.h>
#include <device/PL03x.h>
#include <stdio.h>

int __attribute__((section(".app_timer"))) timer_entry(int process_id, int state) {
	char timer_name[] = "timer0";
	char buffer[32];

	k_ddm_device_t * timer0 = k_ddm_get_device(timer_name);

	uint32_t time = dev_PL03x_get(timer0);
	itoa(time, buffer, 10);

	puts(timer_name);
	puts(": ");
	puts(buffer);
	puts("\r\n");

    return 0;
}
