#include "main.h"

/**
 * more_numbers - Prints 10 times the numbers, from 0 to 14
 *
 * Return: 10 times of the numbers since 0 up to 14
 *
 */

void more_numbers(void)
{
	int c, i;


	for (c = 0; c < 10; c++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i > 9)
				_putchar((i / 10) + '0');

			_putchar((i % 10) + '0');
		}
		_putchar('\n');
	}
}
