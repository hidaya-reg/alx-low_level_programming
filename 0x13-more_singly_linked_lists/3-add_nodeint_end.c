#include "lists.h"

/**
 * add_nodeint_end - adds new node at the end
 * @head: listint_t
 * @n: data in the new node
 * Return: address of the new element, NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new, *cursor;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->next = NULL;

	new->n = n;

	if (*head)
	{
		cursor = *head;
		while (cursor->next != NULL)
			cursor = cursor->next;

		cursor->next = new;
	}
	else
		*head = new;
	return (new);
}
