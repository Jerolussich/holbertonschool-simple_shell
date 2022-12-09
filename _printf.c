#include "main.h"

/**
 * _printf - Writes output to stdout
 * @format: String to be printed
 *
 * Return: Number of characters printed, minus the null byte
*/

int _printf(const char *format, ...)
{
	int i, strlen = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1); /* format string cannot be NULL */

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%') /* Looks for specifier ('%' and next char) */
		{
			if (format[i + 1] == '\0')
				return (-1); /* format string cannot end with '%' */

			strlen += get_printf_func(args, format[i + 1]); /* Updates print count */
			i++; /* Skips one string memory space to not print specifier char */
		}

		else
		{	/* Prints and counts printed chars if no '%' was found */
			_putchar(format[i]);
			strlen++;
		}
	}

	va_end(args);
	return (strlen);
}

/**
 * get_printf_func - Selects correct function
 * @args: Arguments
 * @spec: Character corresponding to printf specifier (format[i + 1])
 *
 * Return: Pointer to selected function or length of string printed
*/

int get_printf_func(va_list args, char spec)
{
	strprt_t letter[] = {
		{"c", print_c},
		{"%", print_p},
		{"s", print_s},
		{"d", print_num},
		{"i", print_num},
		{NULL, NULL}
	}; /* See main.h */

	int i = 0;

	while (letter[i].specifier && spec)
	{	/* Checks if spec matches with any function */
		if (letter[i].specifier[0] == spec)
		{	/* If there is a match, it returns the correct function */
			return ((letter[i].f)(args));
		}
		i++;
	}
	/* If no match is found, prints '%' and spec */
	_putchar('%');
	_putchar(spec);
	return (2); /* Returns length (2 chars printed) */
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
