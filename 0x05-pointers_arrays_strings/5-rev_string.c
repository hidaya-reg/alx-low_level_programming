/**
 * rev_string - function that reverse a string
 * @s: string to reverse
 * Return: void (string s reversed)
 */

void rev_string(char *s)
{
	int i, j, l;
	char tmp;

	i = 0;
	j = 0;


	while (*(s + i) != '\0')
		i++;

	l = i - 1;

	for (j = 0; j < l && l >= 0; j++, l--)
	{
		tmp = s[j];
		s[j] = s[l];
		s[l] = tmp;
	}
}
