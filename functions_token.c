#include "main.h"
/**
 * tokenize_buffer - tokenizes arguments given by the user
 * @buffer: string containing the arguments
 * Return: array of strings containing each argument
 */
char **tokenize_buffer(char *buffer)
{
	size_t buffsize = 1024;
	int i;
	char *token = NULL, *b = NULL, **token_array = NULL;

	token_array = malloc(buffsize);
	if (!token_array)
	{
		free(buffer);
		perror("Malloc error: ");
		exit(0);
	}
	b = strdup(buffer);
	token = strtok(b, " \t\n");
	for (i = 0; token; i++)
	{
		token_array[i] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	token_array[i] = NULL;
	free(b);
	return (token_array);
}
