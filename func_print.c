#include <stdio.h>
#include "main.h"
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

	if (str == NULL)
		str = "(null)";

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
	(void)args;
	_putchar('%');
	return (1);
}

/* preparation de la recursion, je declare avant */
int print_number(int n);

/**
* print_int - récupère un entier de la va_list et l'affiche
* @args: liste des arguments
* Return: nombre de caractères affichés
*/
int print_int(va_list args)
{
	int n;

	n = va_arg(args, int);
	return (print_number(n));
}

/**
* print_number - affiche un entier en utilisant la récursion
* @n: le nombre à afficher
* Return: nombre de caractères affichés
*/
int print_number(int n)
{
	int count = 0;

	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_number(num / 10);

	_putchar((num % 10) + '0');
	count++;
	return (count);
}
