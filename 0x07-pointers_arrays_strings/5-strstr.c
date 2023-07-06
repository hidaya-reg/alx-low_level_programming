/**
 * _strstr - function that locates a substring
 * @haystack: string to search
 * @needle: substring we are searching for in haystack
 * Return: pointer that point to the beginning of tneedle in haystack
 */

char *_strstr(char *haystack, char *needle)
{
	int i, n;
	char *p = 0;

	n = 0;
	while (needle[n] != '\0')
		n++;

	while (*haystack)
	{
		for (i = 0; needle[i]; i++)
		{
			if (haystack[i] != needle[i])
				break;
		}
		if (i != n)
			haystack++;
		else
			return (haystack);
	}
		return (p);
}
