/**
 * _strchr - function that locate a character in a string
 * @s: input string
 * @c: character we're looking for
 * Return: pointer to the first occurence of character c in the string s
 * or null if character not found
 */

char *_strchr(char *s, char c)
{
	char *p = 0;

	while (*s != '\0')
	{
		if (*s != c)
			s++;
		else
		{
			p = s;
			return (p);
		}
	}
	if (c == '\0')
		return (s);

	return (p);
}
