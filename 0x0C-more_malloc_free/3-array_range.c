#include <stdlib.h>
/**
 * array_range - function that creates an array of integers
 * @min: minimum integers @min included
 * @max: maximum integer @max included
 * Return: pointer to the newly created array
 * if min > max return NULL
 * if malloc fails return NULL
 */

int *array_range(int min, int max)
{
	int *p;
	int i, len;

	len = max - min + 1;

	if (min > max)
		return (NULL);

	p = malloc(sizeof(int) * len);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		p[i] = min++;

	return (p);
}
