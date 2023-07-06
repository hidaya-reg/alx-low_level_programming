#include "main.h"

/**
 * get_bit - returns the value of a bit at index
 * @n: integer to get the bit of given index
 * @index: index of the bit wa want to get
 * Return: the value of the bit at index, -1 if error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	i = n >> index;
	return (i & 1);
}
