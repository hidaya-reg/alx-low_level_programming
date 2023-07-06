/**
 * _memcpy - function that copies n bytes from src to dest
 * @dest: pointer where to copy
 * @src: pointer to copy characters from
 * @n: number of bytes to copy
 * Return: pointer dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(dest + i) = *(src + i);

	return (dest);
}
