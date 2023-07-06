#include <stdio.h>

/**
 * main - Entry point
 * Return: 0
 */

int main(void)
{
	int d, max;
	long int n;

	d = 2;
	max = 1;
	n = 612852475143;
	while (n > 1)
	{
		while (n % d == 0)
			n /= d;
		d = d + 1;
		if (d * d > n)
		{
			if (n > 1)
			{
				if (n > max)
					max = n;
				break;

			}
		}
	}
	printf("%ld\n", n);
	return (0);
}

