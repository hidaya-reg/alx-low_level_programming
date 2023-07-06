/**
 * _strncat - function that concatenates two strings
 * @dest:  the first string to append
 * @src: the second string to append
 * @n: number of bytes to append from src
 * Return: pointer dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, l;

	for (l = 0; *(dest + l) != '\0'; l++)
		continue;

	for (i = 0; *(src + i) != '\0'; i++)
	{
		if (i < n)
		*(dest + l + i) = *(src + i);
		else
			break;
	}

	return (dest);
}
