/**
 * get_env - search env por specific line
 * @name: word to look for in env
 * Return: return NULL if failed or pointer to path
 */
char *get_env(char *name)
{
	size_t buffsize = 1024;
	int i;
	char *token = NULL, *token_cpy = NULL, *buff = NULL;

	if (!environ)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{	
		buff = strdup(environ[i]);
		token = strtok(buff, "=");

		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token)
			{
				token_cpy = strdup(token);
				free(buff);
				return (token_cpy);
			}
			free(buff);
		}
		free(buff);
	}
}
/**
 * attach_path - add corresponding path to command given
 * @str: string given with path
 * @input:input given in shell
 * Return: string with full path or NULL if failed
 */

char *attach_path(char *str, char **input)
{
	struct stat st;
	size_t buffsize = 1024;
	int i;
	char *full_path = NULL, *token = NULL, *str_cpy;

	str_cpy = strdup(str);
	token = strtok(str_cpy, ":");
	while (token)
	{
		full_path = malloc(buffsize);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, input[0]);
		if (stat(full_path, &st) == 0)
		{
			free(input[0]);
			free(str_cpy);
			return(full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(str_cpy);
	return (input[0]);
}
void exit_shell(*input)
{
	if (strcmp(token_array[0], "exit") == 0)
	{
		free(buffer);
		free_grid(token_array);
		exit(0);
	}
}
int fork_error_handle(fk)
{
	free(buffer);
	free_grid(token_array);
	perror("Error: ");
	return (0);
}

