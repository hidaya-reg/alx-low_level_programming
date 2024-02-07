#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: The first index where value is located, or -1 if not found.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
		if (prev >= size)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);
	prev -= step;
	for (; prev < size && array[prev] < value; prev++)
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	if (array[prev] == value)
		return (prev);

	return (-1);
}
