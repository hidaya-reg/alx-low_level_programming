/**
 * _strncpy - function thta copy string to a pointer
 * @dest: where we would copy the string
 * @src: the string we want to copy
 * @n: number of bytes to copy from src
 * Return: pointer containing first n bytes of src
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
