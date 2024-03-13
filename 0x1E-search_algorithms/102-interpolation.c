#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 * using the Interpolation search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos = 0, low = 0, high = size - 1;

	if (!array || !size)
		return (-1);

	while (1)
	{
		pos = low + (((double)(high - low) /
					(array[high] - array[low])) * (value - array[low]));
		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		else if (array[pos] > value)
			high = pos - 1;
		else
			low = pos + 1;
	}
	return (-1);
}

