#include "lists.h"
/**
 * add_dnodeint_end - adds new node at the end
 * @head: dlistint_t
 * @n: element to add
 * Return: address of the new element, NULL if it fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *last;

	new = malloc(sizeof(dlistint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;


	new->prev = last;

	last->next = new;
	return (new);
}
