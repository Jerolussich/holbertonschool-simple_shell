#include "main.h"
/**
 * printcharacter - prints character
 * @args: argument
 * Return: length of printed
 */
int printcharacter(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
 * printstring - prints string given
 * @args: argument
 * Return: 6 if null or length of printed
 */
int printstring(va_list args)
{
	char *string = va_arg(args, char *), *null = "(null)";
	int len, i;

	if (string == NULL)
	{
		for (i = 0; null[i]; i++)
			_putchar(null[i]);
		return (6);
	}
	else
	{
		len = strlen(string);
		for (i = 0; i < len; i++)
		{
			_putchar(string[i]);
		}
		return (len);
	}
}
/**
 * printporcentage - print porcentage
 * @args: argument
 * Return: length of printed
 */
int printporcentage(va_list args)
{
	char *string;
	int i;

	string = va_arg(args, char*);
	i = 0;

	while (string[i])
	{
		if (string[i] == '%')
		{
			_putchar('%');
			return (1);
		}
		i++;
	}
	return (0);
}
/**
 * printnumber - returns a value from function printnumberunsig
 * @args: argument
 * Return: printed number of length
 */
int printnumber(va_list args)
{
	int n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		return (printnumberunsig(-n) + 1);
	}
	else
	{
		return (printnumberunsig(n));
	}
}
/**
 * printnumberunsig - print number
 * @n: unsigned int value
 * Return: number given
 */
int printnumberunsig(unsigned int n)
{
	int c = 0;

	if (n / 10 != 0)
	{
		c = printnumberunsig(n / 10);
	}
	return (_putchar((n % 10) + '0') + c);
}
