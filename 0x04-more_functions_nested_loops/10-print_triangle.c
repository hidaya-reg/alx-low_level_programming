#include "main.h"

/**
 * print_triangle - function that prints triangle
 * @size: size of the triangle
 * Return: prtint triangle
 */

void print_triangle(int size)
{
	int line, col;

	line = 1;

	while (line <= size)
	{
		for (col = 0; col < (size - line); col++)
			_putchar(' ');
		for (col = (size - line); col < size; col++)
			_putchar('#');
		_putchar('\n');
		line++;
	}
	if (size <= 0)
		_putchar('\n');
}
