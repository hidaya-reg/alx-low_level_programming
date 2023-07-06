/**
 * cap_string - function that capitalizes all words of a string
 * @str: string to capitalize
 * Return: str capitalized
 */

char *cap_string(char *str)
{
	int i, j;
	char separator[] = " \t\n,;.!?\"(){}";


	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else
				for (j = 0; j <= 12; j++)
				{
					if (separator[j] == str[i])
						str[i + 1] -= 32;
				}
		}
	}
	return (str);
}
