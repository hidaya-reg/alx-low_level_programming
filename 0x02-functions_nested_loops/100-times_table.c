#include "main.h"

/**
 * print_times_table - function that prints n times table, starting with 0
 * @n: multiplication of n
 * Return: multiplication table of n
 */
void print_times_table(int n)
{
	int c, r, d;

	if ((n >= 0) && (n < 15))
	{
		for (r = 0; r <= n; r++)
		{
			_putchar('0');

			for (c = 1; c <= n; c++)
			{
				_putchar(',');
				_putchar(' ');
				d = (r * c);

				if ((d / 100) > 0)
				{
					_putchar((d / 100) + '0');
					_putchar(((d % 100) / 10) + '0');
				}
				else if ((d / 10) > 0)
				{
					_putchar(' ');
					_putchar((d / 10) + '0');
				}
				else
				{
					_putchar(' ');
					_putchar(' ');
				}
				_putchar((d % 10) + '0');
			}
			_putchar('\n');
		}
	}
}


