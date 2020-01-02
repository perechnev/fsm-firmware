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

int __in_range(int __c, int __l, int __h);

int __isalnum(int __c) {
	return	__isdigit(__c) || __isalpha(__c);
}

int __isalpha(int __c) {
	return __islower(__c) || __isupper(__c);
}

int __isblank(int __c) {
	return __c == ' ' || __c == '\t';
}

int __iscntrl(int __c) {
	/*
	 * Control characters are all characters in range between 0x00 (NUL)
	 * and 0x1f (US), plus 0x7f (DEL).
	 */
	 return __c == 0x7f || __in_range(__c, 0x00, 0x1f);
}

int __isdigit(int __c) {
	return __c >= '0' && __c <= '9';
}

int __isxdigit(int __c) {
	return	__isdigit(__c) ||
			__in_range(__c, 'A', 'F') ||
			__in_range(__c, 'a', 'f');
}

int __islower(int __c) {
	return __in_range(__c, 'a', 'z');
}

int __isprint(int __c) {
	return !__iscntrl(__c);
}

int __isspace(int __c) {
	/*
	 * Standard white-space characters are:
	 * 	' ' 	(0x20)	space
	 * 	'\t'	(0x09)	horizontal tab
	 * 	'\n'	(0x0a)	new line
	 * 	'\v'	(0x0b)	vertical tab
	 * 	'\f'	(0x0c)	feed
	 * 	'\r'	(0x0d)	carriage return
	 */
	 return __c == ' ' || __in_range(__c, '\t', '\r');
}

int __isgraph(int __c) {
	return __isprint(__c) && __c != ' ';
}

int __ispunct(int __c) {
	return __isgraph(__c) && !__isalnum(__c);
}

int __isupper(int __c) {
	return __in_range(__c, 'A', 'Z');
}

int __tolower(int __c) {
	return __isupper(__c) ? __c + 0x20 : __c;
}

int __toupper(int __c) {
	return __islower(__c) ? __c - 0x20 : __c;
}

/*
 * Internal implementation
 */

int __in_range(int __c, int __l, int __h) {
	return __c >= __l && __c <= __h;
}
