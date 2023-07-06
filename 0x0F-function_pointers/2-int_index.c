#include "function_pointers.h"

/**
 * int_index - function that searches for an integer
 * @array: array containing integers
 * @size: number of elements in @array
 * @cmp: pointer to the function to be used to compare values
 * Return: int_index the index of the first element for which
 * the @cmp function does not return 0
 * if no element matches, return -1
 * if size <= 0, return -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int int_index;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);

	for (int_index = 0; int_index < size; int_index++)
	{
		if ((*cmp)(array[int_index]))
			return (int_index);
	}
	return (-1);
}
