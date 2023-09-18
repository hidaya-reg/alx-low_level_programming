#include "main.h"

/**
 * _abs - function that computes the absolute value of an integer
 * @i : integer input
 * Return: unsigned integer output
 */

int _abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-1 * i);
}
