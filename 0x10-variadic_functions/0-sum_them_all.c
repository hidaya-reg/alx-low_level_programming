#include "variadic_functions.h"

/**
 * sum_them_all - function returns sum of pall parameters
 * @n: number of parameters
 * Return: sum of paramaeters, 0 if @n == 0
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list parms;
	unsigned int i;
	int sum;

	if (n == 0)
		return (0);

	va_start(parms, n);
	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(parms, int);
	va_end(parms);
	return (sum);
}
