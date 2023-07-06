#include "lists.h"

/**
 * free_listint2 - function that frees listint_t list
 * @head: listint_t
 * Return: void (head free and sets head to NULL)
 */

void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	*head = NULL;
}
