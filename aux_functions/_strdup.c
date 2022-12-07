/**
 * _strdup - copy of the string given as a parameter
 * @str: string of char
 *
 * Description: The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str.
 * Returns NULL if str = NULL
 *
 * Return: a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	char *res = NULL;
	int i = 0;

	if (str != NULL)
		res = malloc(_strlen(str) + 1);
	if (res != NULL)
	{
		for (i = 0; i <= _strlen(str); i++)
			res[i] = str[i];
	}
	return (res);
}
