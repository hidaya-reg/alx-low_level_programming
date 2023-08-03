#include "main.h"

/**
 * flip_bits - returns the number of bits we need to flip
 * @n: source number
 * @m: number we want to get
 * Return: number of bits to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, bits = 0;

	while (xor > 0)
	{
		bits = bits + (xor & 1);
		xor = xor >> 1;
	}
	return (bits);
}
