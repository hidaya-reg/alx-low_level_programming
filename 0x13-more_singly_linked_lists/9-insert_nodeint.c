#include "lists.h"

/**
 * insert_nodeint_at_index - fct that inserts a new node at @idx
 * @head: lisint_t
 * @idx: position to insert new node
 * @n: data of the new element
 * Return: address of the new node, if not possible do not insert new node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *temp, *cursor;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(listint_t));
	if (temp == NULL)
		return (NULL);

	temp->n = n;
	cursor = *head;

	if (idx == 0)
	{
		temp->next = *head;
		*head = temp;
		return (*head);
	}

	while (cursor != NULL)
	{
		if (i == idx - 1)
		{
			temp->next = cursor->next;
			cursor->next = temp;
		}
		i++;
		cursor = cursor->next;
	}
	if (idx > i)
		return (NULL);
	return (temp);
}

