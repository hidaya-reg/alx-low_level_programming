#include <stdlib.h>
/**
 * _calloc - function that allocates memory for an array
 * @nmemb: number of elements
 * @size: size in bytes of each element
 * Return: pointer pointing to new memory
 * if nmemb or size is 0 returns NULL
 * if malloc fails returns NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int len, i;

	len = nmemb * size;
	if (nmemb <= 0 || size <= 0)
		return (NULL);

	p = malloc(len);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		p[i] = 0;

	return (p);
}
