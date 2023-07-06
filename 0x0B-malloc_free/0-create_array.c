#include <stdlib.h>
#include <stdio.h>
/**
 * create_array - function that creates array of chars
 * and initializes it with a specific char
 * @size: size of the array
 * @c: character to initialize array
 * Return: pointer to the array, NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *p;

	p = malloc(sizeof(char) * size);

	if (p == NULL)
	{
		return (NULL);
	}
	if (size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = c;

	return (p);
}
