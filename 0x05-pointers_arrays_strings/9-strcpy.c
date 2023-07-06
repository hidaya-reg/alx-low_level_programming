/**
 * _strcpy - function that copies the string pointed to by src
 * to the buffer pointed to by dest
 * @src: pointer pointing to source string
 * @dest: destination of pointer
 * Return: pointer dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; *(src + i) != '\0'; i++)
		*(dest + i) = *(src + i);
	*(dest + i) = '\0';
	return (dest);
}
