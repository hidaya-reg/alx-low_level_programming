#include <stdio.h>

/**
 * print_array - function that prints n elements of an array of integers
 * @a: array of integers
 * @n: number of elements of a to be printed
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *(a + i));
		if (i != n - 1)
			printf(", ");
	}
	printf("\n");
}
