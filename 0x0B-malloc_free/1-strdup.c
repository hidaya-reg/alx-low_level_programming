#include <stdlib.h>
#include <stdio.h>
/**
 * _strdup - function that returns a pointer to newly allocated space
 * in memory, which contains a copy of *str
 * @str: string to duplicate
 * Return: pointer to the duplicated string, NULL otherwise
 */

char *_strdup(char *str)
{
	char *p;
	int len, i;

	if (str == NULL)
		return (NULL);

	len = 0;
	while (*(str + len) != '\0')
		len++;

	p = malloc(sizeof(char) * (len + 1));

	if (p == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		p[i] = str[i];

	return (p);
}
