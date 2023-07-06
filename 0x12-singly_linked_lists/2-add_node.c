#include "lists.h"
#include <string.h>
/**
 * add_node - adds a new node at the begining of a list_t list
 * @head: head of list_t list
 * @str: data for the new node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	int i = 0;
	list_t *temp;

	temp = malloc(sizeof(list_t));
	if (temp == NULL)
		return (NULL);

	temp->str = strdup(str);

	while (str[i] != '\0')
		i++;

	temp->len = i;
	temp->next = *head;
	*head = temp;
	return (temp);
}
