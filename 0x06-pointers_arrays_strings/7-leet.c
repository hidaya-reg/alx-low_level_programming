/**
 * leet - function that encodes a string into 1337
 * @str: string to encode in 1337
 * Return: encoded stirng
 */

char *leet(char *str)
{
	int i, j;
	char alphabets[] = "aAeEoOtTlL";
	char code[] = "4433007711";

	for (i = 0; *(str + i) != '\0'; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (alphabets[j] == str[i])
				str[i] = code[j];
		}
	}
	return (str);
}
