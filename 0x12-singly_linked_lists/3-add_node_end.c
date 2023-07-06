#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: head of list
 * @str: data of the new element
 * Return: address of the new element, NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	int i = 0;
	list_t *end_node, *cursor;

	end_node = malloc(sizeof(list_t));
	if (end_node == NULL)
		return (NULL);

	if (str)
	{
		end_node->str = strdup(str);
		while (str[i] != '\0')
			i++;
		end_node->len = i;
	}
	else
	{
		end_node->str = NULL;
		end_node->len = 0;
	}
	end_node->next = NULL;
	if (*head)
	{
		cursor = *head;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = end_node;
	}
	else
		*head = end_node;
	return (end_node);
}
