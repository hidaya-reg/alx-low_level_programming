#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - function that creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: new struct dog, NULL if the function fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	int i, len_name, len_owner;
	dog_t *p;

	p = malloc(sizeof(dog_t));

	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	len_name = 0;
	while (name[len_name] != '\0')
		len_name++;
	p->name = malloc(len_name + 1);

	len_owner = 0;
	while (owner[len_owner] != '\0')
		len_owner++;
	p->owner = malloc(len_owner + 1);

	if (p->name == NULL || p->owner == NULL)
	{
		free(p->name), free(p->owner), free(p);
		return (NULL);
	}

	for (i = 0; i < len_name; i++)
		p->name[i] = name[i];
	p->name[len_name] = '\0';

	for (i = 0; i < len_owner; i++)
		p->owner[i] = owner[i];
	p->owner[len_owner] = '\0';

	p->age = age;
	return (p);
}
