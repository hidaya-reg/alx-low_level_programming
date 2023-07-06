#include "main.h"

/**
 * puts_half - function that prints half of a string
 * @str: string to print half of
 * Return: void (print half of string str)
 */
void puts_half(char *str)
{
	int i, l;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	if ((i + 1) % 2 != 0)
		l = (i - 1) / 2;
	else
		l = i / 2;
	for (i = l + 1; str[i] != '\0'; i++)
		_putchar(str[i]);
	_putchar('\n');
}

