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

#include <kernel/kcall.h>

#include <device/pl011.h>
#include <device/PL03x.h>
#include <device/null.h>

#include <stdio.h>
#include <string.h>

extern void k_mm_init();

void init() {
	k_mm_init();

	dev_null_init("null");

	dev_pl011_init(0x101F1000, "tty0");
	dev_pl011_init(0x101F1000, "stdin");
	dev_pl011_init(0x101F1000, "stdout");
	dev_pl011_init(0x101F1000, "stderr");

	// uint32_t lcd0_control = PL111_CONTROL_BEBO |
	// 		PL111_CONTROL_TFT |
	// 		PL111_CONTROL_BPP_24BPP |
	// 		PL111_CONTROL_EN |
	// 		PL111_CONTROL_PWR;
	// dev_pl111_init(0x10120000, "lcd0", lcd0_control);

	dev_PL03x_init(0x101E8000, "timer0");

	process_init();

    kc_spawn(0x4000800);

    process_schedule();

	puts("System is ready to shutdown.");
}
