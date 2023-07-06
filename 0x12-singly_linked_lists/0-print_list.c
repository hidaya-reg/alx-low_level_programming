#include "lists.h"
#include <stdio.h>

/**
 * print_list - function that prints all the elements of a list
 * @h: linked list
 * Return: The number of nodes
 */

size_t print_list(const list_t *h)
{
	unsigned int i;

	for (i = 0; h != NULL; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
	}
	return (i);
}
