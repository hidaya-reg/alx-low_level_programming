/**
 * _strspn - function that gets the length of a prefix substring
 * @s: string we want to get the number of substring from
 * @accept: the substring
 * Return: integer number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, r;

	i = 0;
	r = 0;
	while (*(s + i) != ' ')
	{
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (s[i] == accept[j])
				r++;
		}
		i++;
	}

	return (r);
}
