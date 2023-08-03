#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 * @b: string of 0 and 1 chars
 * Return: converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int i, dec = 0, n = 0;

	if (b == NULL)
		return (0);

	while (*(b + n) != '\0')
	{
		if (*(b + n) == '0' || *(b + n) == '1')
			n++;
		else
			return (0);
	}

	for (i = 0; i < n; i++)
	{
		if (b[i] == '1')
			dec = (dec << 1) | 1;
		else
			dec <<= 1;
	}
	return (dec);
}
