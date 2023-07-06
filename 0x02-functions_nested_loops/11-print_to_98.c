#include <stdlib.h>
#include <stdio.h>

/**
 * print_to_98 - function that prints all natural numbers from n to "98"
 * @n: the first printed number, star from here to 98
 * Return: print numbers from n to 98 void
 */

void print_to_98(int n)
{
	int i;

	if (n >= 98)
	{
		for (i = n; i > 98; i--)
			printf("%d, ", i);
	}
	else
	{
		for (i = n; i < 98; i++)
			printf("%d, ", i);
	}
	printf("98\n");
}

