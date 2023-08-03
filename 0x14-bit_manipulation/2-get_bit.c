#include "main.h"

/**
 * get_bit - return the value at given index
 * @n: integer given
 * @index: index of bit we want to get
 * Return: value of bit at given index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	i = n >> index;
	return (i & 1);
}
