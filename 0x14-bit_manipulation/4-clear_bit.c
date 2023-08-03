#include "main.h"

/**
 * clear_bit - set 0 at given index
 * @n: pointer to integer
 * @index: index to set to 0
 * Return: 1 if it worked, 0 otherwise
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	*n = *n & ~(1 << index);

	return (1);
}
