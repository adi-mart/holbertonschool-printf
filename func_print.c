#include <stdio.h>
#include "main.h"
/**
 * print_char - prints a character
 * @c: character to print
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
}
/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * print_prct - prints a percent sign
 * @args: va_list containing the percent sign to print
 * Return: number of characters printed (always 1 for '%')
 */
int print_prct(va_list args)
{
	_putchar("%");
}
