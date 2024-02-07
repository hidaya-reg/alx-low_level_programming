#include <stddef.h>
#include <stdio.h>
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
    size_t mid, i;
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

    mid = size / 2;
    if (array[mid] == value)
    {
        if (mid == 0 || array[mid - 1] != value)
            return (mid);
        else
            return (advanced_binary(array, mid, value));
    }
    else if (array[mid] > value)
    {
        return (advanced_binary(array, mid, value));
    }
    else
    {
        index = advanced_binary(array + mid + 1, size - mid - 1, value);
        return (index == -1 ? -1 : (int)(index + mid + 1));
    }
}
