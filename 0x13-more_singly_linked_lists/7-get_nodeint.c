#include "lists.h"

/**
 * get_nodeint_at_index - returns nth node of a lisint_t
 * @head: listint_t
 * @index: index of the node
 * Return: listint_t node at index @index, NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}

	return (NULL);
}
