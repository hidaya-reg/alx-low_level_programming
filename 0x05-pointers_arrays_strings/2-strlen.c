/**
 * _strlen - function that returns the length of a string
 * @s: the string we want its length
 * Return: length of string s
 */

int _strlen(char *s)
{
	int i;

	i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}
