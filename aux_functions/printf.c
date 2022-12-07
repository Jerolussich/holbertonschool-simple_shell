#include "main.h"
/**
 * _printf - print output according to given format
 * @format: character string composed of zero or more directives
 * Return: -1 if NULL, number of characters if succesful
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, counter = 0;

	/* If format is null or if string has a '%' */
	if (!format || !strcmp(format, "%"))
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 0 || format[i + 1] == '%'))
		{
			_putchar('%');
			i++;
			counter++;
		}
		/* Format have a '%' in current position ? */
		else if ((format[i] == '%' && format[i - 1] != '%') || (format[i - 1] == '%' && format [i - 2] == '%' && format[i] == '%'))
		{
			counter += help(args, format[i + 1]);
			i++;
		}
		else
		{
			counter += 1;
			_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
/**
 * help - functions chooses correct function in a structure
 * @args: functions in structure
 * @c: argument given
 * Return: printed value or character length
 */
int help(va_list args, char c)
{
	int j = 0;
	list_t list[] = {
		{ "c", printcharacter },
		{ "s", printstring },
		{ "%", printporcentage },
		{ "d", printnumber },
		{ "i", printnumber }
	};
	while (j < 5)
	{
		if (*list[j].cs == c)
		{
			return (list[j].f(args));
		}
		j++;
	}
	_putchar('%');
	_putchar(c);
	return (2);
}
