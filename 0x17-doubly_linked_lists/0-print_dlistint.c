#include "lists.h"
/**
 * print_dlistint - print all the elements of dlistint
 * @h: head of a dlistint
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t n = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		n++;
	}
	return (n);
}
