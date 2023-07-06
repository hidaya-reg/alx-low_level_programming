#include "main.h"

/**
 * main - Entry point
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *str = "_putchar";

	while (*str)
	{
		_putchar(*str);
		/* move to next location */
		str++;
	}

	_putchar('\n');

	return (0);
}
