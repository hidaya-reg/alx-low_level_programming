/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: integer distance between two strings
 */

int _strcmp(char *s1, char *s2)
{
	int i, r;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		r = s1[i] - s2[i];
		if (r != 0)
			break;
	}
	return (r);
}
