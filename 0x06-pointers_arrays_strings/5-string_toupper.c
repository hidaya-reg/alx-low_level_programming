/**
 * string_toupper - function that changes all lowercase
 * letters of a string to uppercase
 * @str: the string to convert
 * Return: string converted
 */

char *string_toupper(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
	}
	return (str);
}
