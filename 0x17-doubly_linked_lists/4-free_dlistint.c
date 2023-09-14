#include "lists.h"
/**
 * free_dlistint - frees a dlistint
 * @head: head of dlistint
 * Return: void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;

	while (current != NULL)
	{
		dlistint_t *next = current->next;

		free(current);
		current = next;
	}
}
