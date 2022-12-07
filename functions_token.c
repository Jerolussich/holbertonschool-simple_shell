


void tokenisation(buffer)
{
	size_t buffsize = 1024;
	int i;
	char *token = NULL, *b = NULL , **token_array = NULL;

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
}
