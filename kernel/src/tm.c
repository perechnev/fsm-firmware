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

#include <tm.h>

#define	MAX_TASKS	10

k_tm_task_t k_tm_task_queue[MAX_TASKS];
volatile int task_count;
int task_id_counter;

void k_tm_init() {
	task_count = 0;
	task_id_counter = 0;
}

void k_tm_run(k_tm_task_entry_f entry, char * name) {
	task_id_counter++;

	k_tm_task_queue[task_count].entry = entry;
	k_tm_task_queue[task_count].state = 0;
	k_tm_task_queue[task_count].name = name;
	k_tm_task_queue[task_count].id = task_id_counter;

	task_count++;
}

void k_tm_run_scheduler() {
	while (task_count > 0) {
		for (int i = 0; i < task_count; i++) {
			k_tm_task_entry_f entry = k_tm_task_queue[i].entry;
			int state = k_tm_task_queue[i].state;
			
			int status = entry(i, state);
			k_tm_task_queue[i].state = status;
			
			/*
			 * Remove task if it finished.
			 */
			if (status == RETURN_STATUS_EXIT) {
				if (task_count > 2) {
					for (int j = 0; j < task_count - 1; j++) {
						k_tm_task_queue[j] = k_tm_task_queue[j + 1];
					}
				}
				i--;
				task_count--;
			}
		}
	}
}
