#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_char - prints a character
 * @args: va_list containing the character to print
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	_putchar(c);
	return (1);
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
	return (i);
}
/**
 * print_prct - prints a percent sign
 * @args: va_list (not used)
 * Return: number of characters printed (always 1 for '%')
 */
int print_prct(va_list args)
{
	_putchar('%');
	return (1);
}
/**
 * print_int - prints an integer
 * @args: va_list containing the integer to print
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int num = va_arg(args, int);
	unsigned int abs_num;
	int len = 0;
	unsigned int divisor;
	char digit;
	if (num < 0)
	{
		write(1, "-", 1);
		len++;
		abs_num = (unsigned int)(-num);
	}
	else
	{
		abs_num = (unsigned int)num;
	}
	if (abs_num == 0)
	{
		write(1, "0", 1);
		return (len + 1);
	}
	divisor = 1;
	for (; abs_num / divisor > 9; divisor *= 10)
		;
	for (; divisor > 0; divisor /= 10)
	{
		digit = (char)((abs_num / divisor) + '0');
		write(1, &digit, 1);
		abs_num %= divisor;
		len++;
	}
	return (len);
}
