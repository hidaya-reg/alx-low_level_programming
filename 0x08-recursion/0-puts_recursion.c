#include "main.h"
/**
 * _puts_recursion - function that prints a string, followed by a new line
 * @s: string to print
 * Return: void print strint to std output
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(s[0]);
	_puts_recursion(s + 1);
}
