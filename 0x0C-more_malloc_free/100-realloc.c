#include <stdlib.h>
/**
 * _realloc - function that reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes of @ptr
 * @new_size: new size in bytes of the new memory block
 * Return: pointer to new memory block with size @new_size
 * if new_size > old_size, the “added” memory should not be initialized
 * If new_size == old_size do not do anything and return ptr
 * If ptr is NULL, then the call is equivalent to malloc(new_size)
 * If new_size is equal to zero, and ptr is not NULL, then the call is
 * equivalent to free(ptr). Return NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i;
	char *charptr = ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && charptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p = malloc(new_size);

	if (p == NULL)
		return (NULL);

	if (charptr == NULL)
		return (p);

	for (i = 0; i < old_size; i++)
		p[i] = charptr[i];
	free(ptr);

	return (p);
}
