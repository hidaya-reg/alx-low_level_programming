#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - function that concatenates all the arguments of the prog
 * @ac: argument count
 * @av: argument vector
 * Return: pointer to a new string, NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int c, i, j, len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (c = 0; c < ac; c++)
	{
		i = 0;
		while (av[c][i] != '\0')
		{
			i++;
			len++;
		}
	}
	len += ac;

	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);

	j = 0;
	for (c = 0; c < ac; c++)
	{
		for (i = 0; av[c][i] != '\0'; i++)
		{
			str[j] = av[c][i];
			j++;
		}
		if (str[j] == '\0')
			str[j++] = '\n';
	}
	return (str);
}
