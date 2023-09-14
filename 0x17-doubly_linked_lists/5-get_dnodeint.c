#include "lists.h"
/**
 * get_dnodeint_at_index - returns the node at some index
 * @head: dlistint_t
 * @index: index of the node
 * Return: return node at index, NULL otherwise
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t len_list = 0;
	unsigned int i;
	dlistint_t *current = head;

	while (current != NULL)
	{
		len_list++;
		current = current->next;
	}
	current = head;

	if (index >= len_list)
		return (NULL);

	for (i = 0; i < index; i++)
	{
		current = current->next;
	}

	return (current);
}
