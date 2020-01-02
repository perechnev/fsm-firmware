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

#ifndef __STDIO_H__
#define __STDIO_H__

#include <stdlib.h>
#include <stddef.h>
#include <kernel/ddm.h>

//EOF	отрицательное целое число типа int, используемое для обозначения конца файла
//BUFSIZ	целое число, равное размеру буфера, используемое функцией setbuf()
//FILENAME_MAX	размер массива char, достаточного для хранения имени любого файла, который может быть открыт
//FOPEN_MAX	число файлов, которые могут быть открыты одновременно; как минимум равно 8
//_IOFBF	сокращение от «input/output fully buffered» (полностью буферируемый ввод-вывод); целое число, которое может быть передано функции setvbuf() для запроса блока буфера ввода и вывода для открытого потока
//_IOLBF	сокращение от «input/output line buffered» (линейно буферируемый ввод-вывод); целое число, которое может быть передано функции setvbuf() для запроса линии буфера ввода и вывода для открытого потока
//_IONBF	сокращение от «input/output not buffered» (не буферируемый ввод-вывод); целое число, которое может быть передано функции setvbuf() для запроса небуферированого ввода и вывода для открытого потока
//L_tmpnam	размер массива char, достаточного для хранения временного имени файла, сгенерированного функцией tmpnam()
//NULL	макрос, расширяющий константу нулевого указателя; то есть константу, представляющую значение указателя, гарантированно указывающего несуществующий адрес объекта в памяти
//SEEK_CUR	целое число, которое может быть передано функции fseek() для запроса позиционирования относительно текущей позиции в файле
//SEEK_END	целое число, которое может быть передано функции fseek() для запроса позиционирования относительно конца файла
//SEEK_SET	целое число, которое может быть передано функции fseek() для запроса позиционирования относительно начала файла
//TMP_MAX	максимальное число уникальных имен файлов, генерируемых функцией tmpnam(); как минимум 25

//typedef ... fpos_t;

#define __FILE		void
#define __stdout	void
#define __stdin		void
#define __stderr	void

#define __FILE		k_ddm_device_t
#define __stdout	(k_ddm_get_device("stdout"))
#define __stdin		(k_ddm_get_device("stdin"))
#define __stderr	(k_ddm_get_device("stderr"))

int	__sprintf	(char *__s, const char *__format, ...);
//fclose	закрывает файл, ассоциированный с переданным ей значением FILE *
//fopen, freopen, fdopen	открывают файл для определённых типов чтения и записи
//remove	удаляет файл (стирая его)
//rename	переименовывает файл
//rewind	работает аналогично fseek (stream, 0L, SEEK_SET), вызванному для потока, со сбросом индикатора ошибок
//tmpfile	создает и открывает временный файл, удаляемый при закрытии через fclose()

//clearerr	очищает EOF и индикаторы ошибок для данного потока
//feof	проверяет, установлен ли индикатор EOF для данного потока
//ferror	проверяет, установлен ли индикатор ошибок для данного потока
//fflush	принудительно записывает вывод, предназначенный для помещения в буфер, в файл, ассоциированный с данным потоком
//fgetpos	сохраняет позицию указателя файла потока, ассоциированный с его первым аргументом (FILE *), в его второй аргумент (fpos_t *)
//fgetc	возвращает один символ из файла
//fgets	получает строку из файла (оканчивающуюся символом перевода строки или конца файла)
//fputc	записывает один символ в файл
//fputs	записывает строку в файл
//ftell	возвращает указатель позиции файла, который может быть передан fseek
//fseek	производит смещение от текущей позиции в файле на указанное количество байт, или от его начала или конца, в указанном направлении.
//fsetpos	устанавливает указатель позиции файла потока, ассоциированный с его первым аргументом (FILE *), как хранимый во втором его аргументе (fpos_t *)
//fwrite	записывает данные в файл
//getc	считывает и возвращает символ из данного потока и изменяет указатель позиции файла; позволяет использоваться как макрос с теми же эффектами, что и fgetc, кроме того, что может вычислять поток более одного раза
//gets	считывает символы из stdin до символа перевода строки и хранит их в своём единственном аргументе
//printf, vprintf	используются для вывода в стандартный поток вывода
//fprintf, vfprintf	используются для вывода в файл
//sprintf, snprintf, vsprintf	используются для вывода в массив типа char (Строка в языке Си)
//perror	записывает сообщение об ошибке в stderr
//putc	записывает и возвращает символ в поток и изменяет указатель позиции файла на него; можно использовать как макрос с теми же свойствами, что и fputc, кроме того, что он может обрабатывать поток более одного раза
//putchar, fputchar	аналогичны putc(stdout)
//scanf, vscanf	используются для ввода из стандартного потока ввода
//fscanf, vfscanf	используются для ввода из файла
//sscanf, vsscanf	используются для ввода из массива char (то есть Строка в языке Си)
//setbuf
//setvbuf	устанавливает режим буферизации для данного потока
//tmpnam	создает имя временного файла
//ungetc	помещает символ обратно в поток
//int		__getchar	(void);

int		__puts		(const char *s);
__size_t	__fread	(void *, __size_t, __size_t, __FILE *);

#define FILE		__FILE
#define stdout		__stdout
#define stdin		__stdin

#define	sprintf		__sprintf
#define puts		__puts
#define fread		__fread
//#define getchar		__getchar

#endif /* __STDIO_H__ */
