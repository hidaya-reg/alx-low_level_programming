#include "lists.h"

/**
 * sum_listint - fct that returns the sum of the data (n)
 * in listint_t
 * @head: listint_t list
 * Return: sum of all data(n) of @head, 0 if head is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
