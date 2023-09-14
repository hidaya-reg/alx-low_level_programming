#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts new node at given position
 * @h: dlistint_t
 * @idx: index of new node
 * @n: data of new node
 * Return: address of new node, NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *temp = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	while (temp != NULL && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}
	if (temp == NULL)
	{
		free(new);
		return (NULL);
	}
	new->prev = temp;
	new->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = new;
	temp->next = new;
	return (new);
}
