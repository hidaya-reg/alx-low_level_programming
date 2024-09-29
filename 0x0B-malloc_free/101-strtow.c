#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * length - function claculate length of string
 * @str: string to split
 * Return: length of str
 */

int length(char *str)
{
	int l = 0;

	while (str[l])
	{
		l++;
	}
	return (l);
}

/**
 * strow - function that splits a string into words.
 * @str: string to split
 * Return: array containing words, NULL if str is NULL
 */
char **strtow(char *str)
{
	char **array;
	int i = 0, j, k, lw, w = 0;

	if (str == NULL || length(str) == 0)
		return (NULL);
    while (str[i])
	{
		if (str[i] != ' ')
		{
			for (j = 0; str[i] && str[i + j] != ' '; j++)
				i++;
			w++;
		}
		else
			i++;
	}
	array = malloc(sizeof(char *) * (w + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
    w = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			lw = 0;
			while (str[i + lw] && str[i + lw] != ' ')
				lw++;
			array[w] = malloc(sizeof(char) * (lw + 1));
			if (array[w] == NULL)
			{
				for (k = 0; k < w; k++)
					free(array[k]);
				free(array);
				return (NULL);
			}
			for (j = 0; j < lw; j++)
				array[w][j] = str[i + j];
			array[w][j] = '\0';
			i += lw;
			w++;
		}
		else
			i++;
	}
	array[w] = NULL;
	return (array);
}
