#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	int first;
	int second;

	for (first = '0'; first < '9'; first++)
	{
		for (second = first + 1; second <= '9'; second++)
		{
			if (first != second)
			{
				putchar(first);
				putchar(second);
				if (first == '8' && second == '9')
					continue;

				putchar(',');
				putchar(' ');
			}
		}

	}
	putchar('\n');

	return (0);
}
