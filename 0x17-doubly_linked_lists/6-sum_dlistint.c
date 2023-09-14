#include "lists.h"
/**
 * sum_dlistint - returns sum of all the data of dlisint
 * @head: dlistint
 * Return: sum of all elements, 0 if head is empty
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current = head;

	if (head == NULL)
		return (0);

	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
