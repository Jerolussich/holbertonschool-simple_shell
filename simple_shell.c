#include "main.h"

/**
 * main - shell
 * @ac: argument count
 * @av: argument vector
 * Return: return -1 if failed or command output
 */
int main(int ac, char **av)
{
	size_t ptr = 0;
	int bytes_read, success;
	char *buffer = NULL, **token_array = NULL;

	while (1)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		bytes_read = getline(&buffer, &ptr, stdin);
		if (bytes_read == -1) /* ctrl+d handler */
		{
			free(buffer);
			exit(0);
		}
		token_array = tokenize_buffer(buffer);
		if (!token_array[0]) /* if first argument is " " before tokenized */
		{
			free_grid(token_array);
			continue;
		}
		if (_strcmp(token_array[0], "exit") == 0) /* exit command */
			shell_exit(token_array, buffer);
		/* Ssearches for a valid path, if one is found it is executed  */
		success = execute(token_array, buffer);
		if (success == -1)  /* if command not found*/
		{
			continue;
		}
	}
}
