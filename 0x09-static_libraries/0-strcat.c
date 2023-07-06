#include "main.h"
/**
 * _strcat - function appends two strings
 * @dest: first string to concate
 * @src: second string to concate
 * Return: pointer dest containing both strings
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; *(dest + i) != '\0'; i++)
		continue;

	for (j = 0 ; *(src + j) != '\0'; j++)
		*(dest + i + j) = *(src + j);

	return (dest);
}
