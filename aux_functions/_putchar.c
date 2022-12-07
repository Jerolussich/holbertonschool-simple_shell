#include <unistd.h>

/**
 * _putchar - print a character
 * @c: character
 * Return: return printed value
 *
 */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
