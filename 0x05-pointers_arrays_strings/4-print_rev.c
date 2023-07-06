#include "main.h"

/**
 * print_rev - function that prints a string, in reverse
 * @s: string to reverse
 * Return: void (s printed in reverse)
 */

void print_rev(char *s)
{
	int i;
	int len;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	len = i;

	for (i = len - 1; i >= 0; i--)
		_putchar(*(s + i));

	_putchar('\n');
}
