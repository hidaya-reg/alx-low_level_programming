#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @d: signed digit
 * Return: int output
 */

int print_last_digit(int d)
{
	int r;

	if (d >= 0)
		r = (d % 10);
	else
		r = -1 * (d % 10);

	_putchar(r + '0');
	return (r);
}
