#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t
 * and returns head node's data (n)
 * @head: listint_t
 * Return: head node's data (n), 0 if @head is empty
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);
	return (n);
}
