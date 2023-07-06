#include "lists.h"

/**
 * free_listint - function that frees a lisint_t list
 * @head: listint_t
 * Return: void (@head freed)
 */

void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
