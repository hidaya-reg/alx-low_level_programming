#include "lists.h"

/**
 * dlistint_len - returns number of elements in dlist_t
 * @h: head of dlistint_t
 * Return: number of elements of h
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t n = 0;

	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	return (n);
}
