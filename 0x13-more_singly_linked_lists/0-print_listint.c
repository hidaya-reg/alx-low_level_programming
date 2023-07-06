#include "lists.h"

/**
 * print_listint - function that prints all the elements of listint_t
 * @h: listint_t
 * Return: number of node in lisint @h
 */

size_t print_listint(const listint_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
