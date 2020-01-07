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


#include <ctype.h>

int __in_range(int c, int l, int h);

int isalnum(int c) {
	return isdigit(c) || isalpha(c);
}

int isalpha(int c) {
	return islower(c) || isupper(c);
}

int isblank(int c) {
	return c == ' ' || c == '\t';
}

int iscntrl(int c) {
	/*
	 * Control characters are all characters in range between 0x00 (NUL)
	 * and 0x1f (US), plus 0x7f (DEL).
	 */
	 return c == 0x7f || __in_range(c, 0x00, 0x1f);
}

int isdigit(int c) {
	return __in_range(c, '0', '9');
}

int isxdigit(int c) {
	return isdigit(c) || __in_range(c, 'A', 'F') || __in_range(c, 'a', 'f');
}

int islower(int c) {
	return __in_range(c, 'a', 'z');
}

int isprint(int c) {
	return !iscntrl(c);
}

int isspace(int c) {
	/*
	 * Standard white-space characters are:
	 * 	' ' 	(0x20)	space
	 * 	'\t'	(0x09)	horizontal tab
	 * 	'\n'	(0x0a)	new line
	 * 	'\v'	(0x0b)	vertical tab
	 * 	'\f'	(0x0c)	feed
	 * 	'\r'	(0x0d)	carriage return
	 */
	 return c == ' ' || __in_range(c, '\t', '\r');
}

int isgraph(int c) {
	return isprint(c) && c != ' ';
}

int ispunct(int c) {
	return isgraph(c) && !isalnum(c);
}

int isupper(int c) {
	return __in_range(c, 'A', 'Z');
}

int tolower(int c) {
	return isupper(c) ? c + 0x20 : c;
}

int toupper(int c) {
	return islower(c) ? c - 0x20 : c;
}

/*
 * Internal implementation
 */

int __in_range(int c, int l, int h) {
	return c >= l && c <= h;
}
