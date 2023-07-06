#include "lists.h"

/**
 * delete_nodeint_at_index - fct that deletes node at index
 * @head: listint_t
 * @index: index of the node
 * Return: 1 if it succeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;

	listint_t *cursor, *temp;

	cursor = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = cursor->next;
		free(cursor);
		return (1);
	}

	if (index == 1)
	{
		cursor = (*head)->next;
		(*head)->next = cursor->next;
		free(cursor);
		return (1);
	}

	while (i < index - 1)
	{
		if (cursor->next == NULL)
			return (-1);
		i++;
		cursor = cursor->next;
		temp = cursor->next;
	}
	cursor->next = temp->next;
	free(temp);

	return (1);
}
