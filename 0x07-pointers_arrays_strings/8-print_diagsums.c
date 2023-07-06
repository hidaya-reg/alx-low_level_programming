#include <stdio.h>
/**
 * print_diagsums - function that prints the sum of
 * the two diagonals of a square matrix
 * @a: square matrix of integers
 * @size: dimension of the matrix
 * Return: void print the sums of diagonals
 */

void print_diagsums(int *a, int size)
{
	int i, j, s1, s2;

	s1 = 0;
	s2 = 0;
	i = 0;
	j = size - 1;

	while (i <= (size * size))
	{
		s1 = s1 + a[i];
		i = i + size + 1;
	}

	while (j < (size * size - 1))
	{
		s2 += a[j];
		j += size - 1;
	}
	printf("%d, %d\n", s1, s2);
}
