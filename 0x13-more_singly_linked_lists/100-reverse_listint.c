#include "lists.h"

/**
 * reverse_listint - fct that reverses a listint_t linked list.
 * @head: listint_t
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		*head = next;
	}

	*head = prev;
	return (*head);
}
