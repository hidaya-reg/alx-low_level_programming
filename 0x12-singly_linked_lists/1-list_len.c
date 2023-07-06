#include "lists.h"

/**
 * list_len - returns the number of elements in list_t list
 * @h: list_t list
 * Return: number of elements in h
 */

size_t list_len(const list_t *h)
{
	unsigned int i;

	i = 0;
	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
