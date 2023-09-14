#include "lists.h"

/**
 * add_dnodeint - adds new node at the beginning
 * @head: dlistint_t
 * Return: adress of new element, NULL otherwise
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return NULL;

	new->n = n;
	new->prev = NULL;

	if (*head != NULL)
	{
		new->next = *head;
		(*head)->prev = new;
	}
	else
		new->next = NULL;
	*head = new;
	return (new);
}
