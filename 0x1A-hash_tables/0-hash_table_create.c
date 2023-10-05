#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table
 * NULL otherwise
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *new_table = NULL;

	if (size <= 0)
		return (NULL);

	/* Allocate memory for the hash table */
	new_table = malloc(sizeof(hash_table_t));
	if (new_table == NULL)
		return (NULL);

	/* Allocate memory for the array of pointers */
	new_table->array = malloc(sizeof(hash_node_t *) * size);
	if (new_table->array == NULL)
	{
		free(new_table);
		return(NULL);
	}

	/* Initialize the array elts to NULL */
	for (i = 0; i < size; i++)
		new_table->array[i] = NULL;

	new_table->size = size;
	return (new_table);
}
