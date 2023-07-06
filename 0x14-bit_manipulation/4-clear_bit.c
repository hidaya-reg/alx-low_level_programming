#include "main.h"

/**
 * clear_bit - sets the value 0 at @index
 * @n: pointer to integer
 * @index: index
 * Return: 1 if succeed, -1 otherwise
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n & ~(1 << index);
	return (1);
}
