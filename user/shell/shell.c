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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STATE_DEFAULT			1
#define	STATE_GETTING_CHARS		2
#define	STATE_EXECUTING			3

char command_buffer[256];
char current_symbol;

int __attribute__((section(".app_shell"))) shell_entry(int state) {
	int read;
	
	switch (state) {
		case 0:
            return STATE_DEFAULT;
			
		case STATE_DEFAULT:
			current_symbol = 0;
			puts("sh# ");
            return STATE_GETTING_CHARS;
			
		case STATE_GETTING_CHARS:
			read = fread(command_buffer + current_symbol, sizeof(char), 1, stdin);
			
			if (read > 0) {
				puts(command_buffer + current_symbol);
			}
			
			if (command_buffer[current_symbol] == '\r') {
				puts("\r\n");
				command_buffer[current_symbol] = '\0';
                return STATE_EXECUTING;
			}
			
			current_symbol += read;
			command_buffer[current_symbol + 1] = '\0';

            return STATE_GETTING_CHARS;
			
		case STATE_EXECUTING:
			if (strcmp(command_buffer, "exit") == 0) {
                return 0;
			}
			
//			int status = k_am_run(command_buffer);
//			if (status == -1) {
//				puts("Command not found: "); puts(command_buffer); puts("\r\n");
//			}

            return STATE_DEFAULT;
	}

    return 0;
}
