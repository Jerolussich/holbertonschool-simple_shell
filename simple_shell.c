#include "main.h"

/**
 * main - shell
 * Return: return -1 if failed or command output
 */
int main(void)
{
	size_t ptr = 0;
	int bytes_read, success, count = 0;
	char *buffer = NULL, **token_array = NULL;

	while (1)
	{	count++;
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
		if (_strcmp(token_array[0], "env") == 0) /*  print env command*/
		{
			print_env();
			continue;
		}
		if (_strcmp(token_array[0], "exit") == 0) /* exit command */
			shell_exit(token_array, buffer);
		/* searches for a valid path, if one is found it is executed  */
		success = execute(token_array, buffer, count);
		if (success == -1)  /* if command not found*/
		{
			continue;
		}
	}
}
