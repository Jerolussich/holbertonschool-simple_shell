#include "main.h"

/**
 * main - shell 
 * @ac: argument count
 * @av: argument vector
 * Return: return -1 if failed or command output
 */
int main (int ac, char **av)
{
	struct stat st;
	size_t ptr = 0, buffsize = 1024;
	int i, stream, check, fk;
	char *buffer = NULL, *b = NULL, *token = NULL, **token_array = NULL, *path = NULL;

	while (1)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
			/* Prompt display */
		stream = getline(&buffer, &ptr, stdin);
		if (stream == -1)
		{
			printf("ctrld ashei\n");
			free(buffer);
			exit(0);
		}
			/* Argument tokenisation */
		token_array = malloc(buffsize);
		if (!token_array)
		{
			free(buffer);
			perror("Error: ");
			return (-1);
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
		if (!token_array[0]) // if token_array[0] is made of tokens
		{
			free_grid(token_array);
			continue;
		}

			/* Exit function */
		if (strcmp(token_array[0], "exit") == 0)
		{
			free(buffer);
			free_grid(token_array);
			exit(0);
		}
			/* Command execution */
		check = stat(token_array[0], &st);
		if (check == 0) // if given full path
		{
			fk =  fork();
			if (fk < 0)
			{
				free(buffer);
				free_grid(token_array);
				perror("Error: ");
				return (-1);
			}
			if (fk == 0) // child process
				execve(token_array[0], token_array, environ);
			else // parent process
			{
				free_grid(token_array);
				wait(NULL);
			}
		}
		else if (check == -1) // if full path not given
		{
			path = get_env("PATH");
			token_array[0] = attach_path(path, token_array);
			free(path);
			check = stat(token_array[0], &st);
			if (check == 0)
			{
				fk =  fork();
				if (fk < 0)
				{
					free(buffer);
					perror("Error: ");
					return (-1);
				}
				if (fk == 0) // child process
					execve(token_array[0], token_array, environ);
		
			}
			if (check == -1) // if command not found
			{
				printf("Command not found\n");
				free_grid(token_array);
				continue;
			}
			else // parent process
				wait(NULL);

			free_grid(token_array);
		}
	}
}
