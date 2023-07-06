#include "main.h"

/**
 * _puts - function that prints a string
 * @str: the string to print
 * Return: void (str printed to stdout)
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		_putchar(*(str + i));
		i++;
	}

	_putchar('\n');
}
