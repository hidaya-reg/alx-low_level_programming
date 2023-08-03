#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at given index
 * @n: integer
 * @index: index of integer to set to 1
 * Return: 1 if it worked, -1 otherwise
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n ^ (1 << index);
	return (1);
}
