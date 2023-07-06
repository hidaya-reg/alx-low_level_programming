#include "3-calc.h"
/**
 * op_add - function adds two integers
 * @a: first integer
 * @b: second integer
 * Return: sum of @a and @b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - function returns diference two integers
 * @a: first integer
 * @b: second integer
 * Return: difference of @a and @b
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - function multiplies two integers
 * @a: first integer
 * @b: second integer
 * Return: product of @a and @b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - function divide two integers
 * @a: first integer
 * @b: second integer
 * Return: division of @a by @b
 */
int op_div(int a, int b)
{
	if (b != 0)
		return (a / b);
	printf("Error\n");
	exit(100);
}

/**
 * op_mod - function returns modulo two integers
 * @a: first integer
 * @b: second integer
 * Return: modulo of @a and @b
 */
int op_mod(int a, int b)
{
	if (b != 0)
		return (a % b);

	printf("Error\n");
	exit(100);
}
