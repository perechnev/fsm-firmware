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

#ifndef __KERNEL_H__
#define __KERNEL_H__

#ifndef K_NULL
#define K_NULL ((void *)0)
#endif

// System
#define KCALL_RESET     0x00
// Memory
#define KCALL_ALLOCATE	0x10
#define KCALL_RETAIN    0x11
#define KCALL_RELEASE   0x12
// Process
#define KCALL_SPAWN     0x20
#define KCALL_KILL      0x21
#define KCALL_SEND      0x22
#define KCALL_RECEIVE   0x23
// Node
#define KCALL_WRITE     0x30
#define KCALL_READ      0x31

int		kcall(int call, int p1);

#endif
