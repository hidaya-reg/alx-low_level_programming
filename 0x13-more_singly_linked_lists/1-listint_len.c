#include "lists.h"

/**
 * listint_len - fct tha returns the number of elements in lisint_t
 * @h: lisint_t
 * Description: returns the number of elements in @h
 * Return: number of elements in lisint_t @h
 */

size_t listint_len(const listint_t *h)
{
	size_t len;

	for (len = 0; h != NULL; len++)
		h = h->next;

	return (len);
}
