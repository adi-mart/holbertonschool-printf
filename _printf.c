#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Arguments à afficher à la place des specifiers
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, total = 0, j;

	format_t formats[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_prct},
		{'d', print_int}, {'i', print_int}, {'\0', NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			for (j = 0; formats[j].specifier; j++)
			{
				if (formats[j].specifier == format[i])
				{
					total += formats[j].func(args);
					break;
				}
			}
			if (!formats[j].specifier)
			{
				_putchar('%');
				_putchar(format[i]);
				total += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			total++;
		}
		i++;
	}
	va_end(args);
	return (total);
}
