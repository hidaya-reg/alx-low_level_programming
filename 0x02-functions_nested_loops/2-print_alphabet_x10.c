#include "main.h"

/**
 * print_alphabet_x10 - function prints 10 times the alphabet
 * Return: 10 times alphabets
 */

void print_alphabet_x10(void)
{
	int counter;
	char alphabet;

	for (counter = 0; counter <= 9; counter++)
	{
		for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
			_putchar(alphabet);

		_putchar('\n');
	}
}
