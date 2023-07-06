#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - function that allocates memory
 * @b: size of memory in bytes
 * Return: Pointer to the allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *p = malloc(b);

	if (p == NULL)
		exit(98);

	return (p);
}
