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
	int i = 0;
	int total = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			format_t formats[] = {
				{'c', print_char},
				{'s', print_string},
				{'%', print_prct},
				{'d', print_int},
				{'i', print_int},
				{'\0', NULL}
			};
			int j = 0;

			i++;
			while (formats[j].specifier)
			{
				if (formats[j].specifier == format[i])
				{
					total += formats[j].func(args);
					break;
				}
				j++;
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
