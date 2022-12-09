#include "main.h"
/**
 * tokenize_buffer - tokenizes arguments given by the user
 * @buffer: string containing the arguments
 * Return: array of strings containing each argument
 */
char **tokenize_buffer(char *buffer)
{
	int i, j = 0, counter = 0;
	char *token = NULL, *b = NULL, **token_array = NULL;

	while (buffer[j])
	{
		if (buffer[j] == 9 || buffer[j] == 10 || buffer[j] == 32)
		{
			j++;
			counter++;
			continue;
		}
		j++;
	}

	token_array = malloc(sizeof(char *) * (counter + 1));
	if (!token_array)
	{
		free(buffer);
		perror("Malloc error: ");
		exit(0);
	}
	b = _strdup(buffer);
	token = strtok(b, " \t\n");
	for (i = 0; token; i++)
	{
		token_array[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
	}
	token_array[i] = NULL;
	free(b);
	return (token_array);
}
