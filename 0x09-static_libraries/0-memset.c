/**
 * _memset - function that fills memory with a constant byte
 * @s: input string to fill first n bytes
 * @b: the character to replace the old one
 * @n: number of bytes to replace
 * Return: void s is filled with n characters of 'b'
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		*(s + i) = b;
	return (s);
}
