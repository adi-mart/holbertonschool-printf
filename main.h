#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
* struct format - Structure associant un spécificateur à une fonction
* @specifier: Le caractère de format (ex: 'c', 's', 'd', etc.)
* @func: Pointeur vers la fonction correspondante
*/

typedef struct format
{
	char specifier;

	int (*func)(va_list args);
} format_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_prct(va_list args);
int print_int(va_list args);
int print_number(int n);


#endif
