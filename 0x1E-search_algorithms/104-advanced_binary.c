#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int index;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array:");
	for (i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
		if (i < size - 1)
			printf(",");
	}
	printf("\n");

	index = size / 2;
	if (array[index] == value)
	{
		while (index > 0 && array[index - 1] == value)
			index--;
		return (index);
	}
	else if (array[index] < value)
	{
		int sub_index = advanced_binary(array + index + 1, size - index - 1, value);
		if (sub_index == -1)
			return (-1);
		return (index + sub_index + 1);
	}
	else
		return (advanced_binary(array, index, value));
}
