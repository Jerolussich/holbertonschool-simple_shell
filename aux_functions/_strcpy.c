#include "main.h"

/**
 * *_strcpy - copy the string to a buffer
 * @dest: pointer
 * @src: pointer
 * Return: 0
 **/


char *_strcpy(char *dest, char *src)
{
	int r = 0;

	for (; src[r] != '\0'; r++)
	{
		dest[r] = src[r];
	}

	dest[r] = '\0';

	return (dest);
}
