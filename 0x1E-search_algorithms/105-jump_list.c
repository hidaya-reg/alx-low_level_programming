#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers
 *             using the Jump search algorithm.
 * @list: A pointer to the head of the list to search in.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present in list or list is NULL, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump, step;
    listint_t *current, *prev;

    if (!list)
        return (NULL);

    jump = sqrt(size);
    current = list;
    while (current && current->n < value)
    {
        prev = current;
        step = jump;
        while (current->next && step > 0 && current->n < value)
        {
            prev = current;
            current = current->next;
            printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
            step--;
        }
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           prev->index, current->index);

    printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
    while (prev && prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
        if (!prev->next || prev->n > value)
            return (NULL);
        prev = prev->next;
    }
    if (prev && prev->n == value)
        return (prev);
    return (NULL);
}
