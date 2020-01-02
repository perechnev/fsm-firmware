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

#include "tasks.h"
#include <kernel/tm.h>
#include <stdio.h>

extern k_tm_task_t k_tm_task_queue[];
extern int task_count;

void print_task(k_tm_task_t * task) {
    char buffer[64];

    itoa(task->id, buffer, 10);
    puts(buffer); puts("\t");

    puts(task->name); puts("\t");

    itoa(task->state, buffer, 10);
    puts(buffer); puts("\t");

    itoa(task->entry, buffer, 16);
    puts(buffer);
}

int tasks_entry(int task_id, int state) {
    puts("ID\tName\tState\tEntry\r\n");

    for (register int i = 0; i < task_count; i++) {
        print_task(k_tm_task_queue + i);
        puts("\r\n");
    }

    exit();
}
