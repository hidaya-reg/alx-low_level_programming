#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main(void)
{
	char l_ch;
	char c_ch;

	for (l_ch = 'a'; l_ch <= 'z'; l_ch++)
		putchar(l_ch);
	for (c_ch = 'A'; c_ch <= 'Z'; c_ch++)
		putchar(c_ch);
	putchar('\n');

	return (0);
}
