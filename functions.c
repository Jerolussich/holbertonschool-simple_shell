#include "main.h"
/**
 * get_env - search env por specific line
 * @name: word to look for in env
 * Return: return NULL if failed or pointer to path
 */
char *get_env(char *name)
{
	int i;
	char *token = NULL, *token_cpy = NULL, *buff = NULL;

	if (!environ)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		buff = _strdup(environ[i]);
		token = strtok(buff, "=");
		if (_strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token)
			{
				token_cpy = _strdup(token);
				free(buff);
				return (token_cpy);
			}
			free(buff);
		}
		free(buff);
	}
	return (0);
}
/**
 * attach_path  - add corresponding path to the given command
 * @token_array: input given in shell
 * @buffer: string given by path
 * Return: string with full path or NULL if failed
 */
char *attach_path(char *buffer, char **token_array)
{
	struct stat st;
	size_t buffsize = 1024;
	char *full_path = NULL, *token = NULL, *str_cpy;

	str_cpy = _strdup(buffer);
	token = strtok(str_cpy, ":");
	while (token)
	{
		full_path = malloc(buffsize);
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, token_array[0]);
		if (stat(full_path, &st) == 0)
		{
			free(token_array[0]);
			free(str_cpy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(str_cpy);
	return (token_array[0]);
}
/**
 * shell_exit - exits the shell parent process
 * @token_array: input given in shell
 * @buffer: string given by path
 */
void shell_exit(char **token_array, char *buffer)
{
		free(buffer);
		free_grid(token_array);
		exit(EXIT_SUCCESS);
}
/**
 * fork_handler - creates a child proccess and executes a program
 * @token_array: input given in shell
 * @buffer: string given by path
 * Return: 0 if command executed successfully, exit if fork fails
 */
int fork_handler(char **token_array, char *buffer)
{
	int fk;

	fk =  fork();
	if (fk < 0)
	{
		free(buffer);
		free_grid(token_array);
		perror("Error: ");
		exit(0);
	}
	if (fk == 0) /* child process */
		execve(token_array[0], token_array, environ);
	else /* parent process */
	{
		wait(NULL);
		free_grid(token_array);
		return (0);
	}
	return (0);
}
/**
 * execute - checks if the first argument by the user can be executed
 * @token_array: input given in shell
 * @buffer: string given by path
 * @count: counter of commands sent to shell
 * Return: string with full path or NULL if failed
 */
int execute(char **token_array, char *buffer, int count)
{
	struct stat st;
	int check;
	char *path;

	check = stat(token_array[0], &st);
	if (check == 0) /* if given full path */
		fork_handler(token_array, buffer);
	else if (check == -1) /* if not given full path */
	{
		path = get_env("PATH");
		token_array[0] = attach_path(path, token_array);
		free(path);
		check = stat(token_array[0], &st);
		if (check == 0)
			fork_handler(token_array, buffer);
		if (check == -1)
		{
			_printf("hsh: %i: %s: ", count, token_array[0]);
			perror("");
			free_grid(token_array);
			return (-1);
		}
	}
	return (0);
}
