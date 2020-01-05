// MIT License

// Copyright (c) 2020 Alexander Perechnev <alexander@perechnev.com>

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
#include <memory.h>
#include <process.h>

void __attribute__((interrupt("SWI"))) kcall_handle(int r0, int r1, int r2, int r3) {
	int result = kcall_dispatch(r0, r1, r2, r3);
	__asm__("MOV r7, %0" : : "r" (result));
}

int __attribute__((always_inline)) kcall_dispatch(int call, int r1, int r2, int r3) {
    switch (call) {
        case KCALL_RESET:       break;
        case KCALL_ALLOCATE:    return kcall_handle_allocate(r1);
        case KCALL_RETAIN:      return kcall_handle_retain(r1);
        case KCALL_RELEASE:     return kcall_handle_release(r1);
        case KCALL_SPAWN:       return kcall_handle_spawn(r1);
        case KCALL_KILL:        return kcall_handle_kill(r1);
        case KCALL_SEND:        break;
        case KCALL_RECEIVE:     break;
        case KCALL_WRITE:       break;
        case KCALL_READ:        break;
    }
    // TODO: Need somehow to indicate that kernel call doesn't exist
    return 0;
}

int __attribute__((always_inline)) kcall_handle_allocate(int p1) {
	return (int)memory_allocate(p1)->start;
}

int __attribute__((always_inline)) kcall_handle_retain(int p1) {
    return memory_retain((void *)p1);
}

int __attribute__((always_inline)) kcall_handle_release(int p1) {
    return memory_release((void *)p1);
}

int __attribute__ ((always_inline)) kcall_handle_spawn(int p1) {
    return process_spawn((process_entry *)p1);
}

int __attribute__ ((always_inline)) kcall_handle_kill(int p1) {
    return process_kill(p1);
}
