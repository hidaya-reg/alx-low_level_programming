#include "main.h"

/**
 * set_bit - setes the value of a bit to 1 at @index
 * @n: integer
 * @index: index
 * Return: 1 if it worked, -1 otherwise
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n ^ (1 << index);
	return (1);
}
