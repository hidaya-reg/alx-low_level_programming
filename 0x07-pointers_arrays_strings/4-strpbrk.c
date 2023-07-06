/**
 * _strpbrk - function that searches a string for any of a set of bytes
 * @s: string wher we search for string
 * @accept: string containing the characteres we are looking for
 * Return: a pointer of the first occurence in the string s that matches
 * any of the bytes in accept, or null if no byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int i;
	char *p = 0;

	while (*s)
	{
		for (i = 0; *(accept + i); i++)
		{
			if (*s == *(accept + i))
				return (s);
		}
		s++;
	}
	return (p);
}
