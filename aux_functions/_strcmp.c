
/**
 * _strcmp - concatenate a string
 * @s1: pointer of a string
 * @s2: pointers of a string
 * Return: pointer to string dest
 **/

int _strcmp(char *s1, char *s2)
{

	int i;

	for (i = 0; s2[i] == s1[i] && s1[i] != '\0'; i++)
	{
	}
	if (s1[i] != s2[i])
	{
		return ((s1[i] - s2[i]));
	}
	else
	{
		return (0);
	}
}
