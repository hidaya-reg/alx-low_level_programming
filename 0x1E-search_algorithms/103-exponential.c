#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
int binary_search_exponential(int *array, size_t low, size_t high, int value);
void print_array(int *array, size_t low, size_t high);

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using Exponential search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1, low, high;

	if (array == NULL || size == 0)
		return (-1);
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	low = bound / 2;
	high = (bound < size) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_exponential(array, low, high, value));
}

/**
 * binary_search_exponential - Searches for a value in a sorted array
 *                              of integers using binary search.
 * @array: A pointer to the first element of the array to search in.
 * @low: The lowest index to search from.
 * @high: The highest index to search to.
 * @value: The value to search for.
 *
 * Return: The index where value is located, or -1 if not found.
 */
int binary_search_exponential(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	while (low <= high)
	{
		print_array(array, low, high);
		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

/**
 * print_array - Prints the elements of an array within given bounds.
 * @array: A pointer to the first element of the array.
 * @low: The lowest index to print from.
 * @high: The highest index to print to.
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	printf("Searching in array:");
	for (i = low; i <= high; ++i)
	{
		printf(" %d", array[i]);
		if (i < high)
			printf(",");
	}
	printf("\n");
}
