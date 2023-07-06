#include "main.h"

/**
 * print_number - function tha prints integer
 * @n: integer to print
 * Return: print n
 */

void print_number(int n)
{
	int power, num;
	int boolean;
	
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}

	num = n;
	power = 1;
	boolean = 1;
	while (boolean)
	{
		if (num / (power * 10) > 0)
			power *= 10;
		else
			boolean = 0;
	}
	boolean = 1;
	while (boolean)
	{
		if (power == 1)
		{
			_putchar(num % 10 + '0');
			boolean = 0;
		}
		else
		{
			_putchar((num / power % 10) + '0');
			power /= 10;
		}
	}
}
