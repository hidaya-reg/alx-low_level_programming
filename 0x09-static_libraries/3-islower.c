#include "main.h"

/**
 * _islower - function that checks for liwercase character
 * @c: input one character
 * Return: boolean
 */

int _islower(int c)
{
	if ((c >= 97) && (c <= 122))
		return (1);
	else
		return (0);
}
