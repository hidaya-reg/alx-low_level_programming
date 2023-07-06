#include "main.h"

/**
 * print_square - prints a square
 * @size: input size of the square
 * Return: standard output a square
 */

void print_square(int size)
{
	int line, col;

	for (line = 0; line < size; line++)
	{
		for (col = 0; col < size; col++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
	if (size <= 0)
		_putchar('\n');
}
