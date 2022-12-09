#include "main.h"

/*
 * print_env - print enviroment
 */


void print_env()
{
	int i;
	char *buff = NULL;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
	{
		buff = strdup(environ[i]);
		printf("%s\n", buff);
	}
	free(buff);
	return;
}
