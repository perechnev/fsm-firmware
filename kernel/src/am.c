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
#include <am.h>
#include <tm.h>
#include <mm.h>

#define MAX_APPS	10

k_am_application_t * __app_list[MAX_APPS];
int app_n;

k_am_application_t * get_app(int n) {
	return __app_list[n];
}

void set_app(k_am_application_t * app, int n) {
	__app_list[n] = app;
}

/*
 * Public functions
 */

k_am_application_t * k_am_get_app(char * name) {
	for (int i = 0; i < app_n; i++) {
		char * i_name = get_app(i)->name;
		if (name[0] == i_name[0] && name[1] == i_name[1]) { // FIXME!
			return get_app(i);
		}
	}
	
	return K_NULL;
}

void k_am_init() {
	app_n = 0;
}

void k_am_register(char * name, k_tm_task_entry_f entry) {
	k_am_application_t * app = memory_allocate(sizeof(k_am_application_t))->start;
	app->name = name;
	app->entry = entry;
	
	set_app(app, app_n);
	app_n++;
}

int k_am_run(char * command) {
	k_am_application_t * app = k_am_get_app(command);
	if (app == K_NULL) {
		return -1;
	}
	
	k_tm_run(app->entry, app->name);
	
	return 0;
}
