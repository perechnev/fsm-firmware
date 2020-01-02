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

#include <kernel/mm.h>
#include <kernel/am.h>
#include <kernel/tm.h>

#include <device/pl011.h>
#include <device/PL03x.h>
#include <device/null.h>

#include <stdio.h>
#include <string.h>

#include "user/shell/shell.h"
#include "user/mmap/mmap.h"
#include "user/apps/apps.h"
#include "user/devices/devices.h"
#include "user/tasks/tasks.h"
#include "user/timer/timer.h"

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
	
	k_am_init();

	k_am_register("shell", shell);
	k_am_register("mmap", mmap_entry);
	k_am_register("apps", apps_entry);
	k_am_register("devices", devices_entry);
	k_am_register("tasks", tasks_entry);
	k_am_register("timer", timer_entry);

	k_tm_init();
	
	k_am_run("shell");
	k_tm_run_scheduler(); // Run loop

	puts("System is ready to shutdown.");
}
