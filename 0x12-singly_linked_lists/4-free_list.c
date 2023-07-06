#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: head of list
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *cursor;

	while (head)
	{
		cursor = head->next;
		free(head->str);
		free(head);
		head = cursor;
	}
}
