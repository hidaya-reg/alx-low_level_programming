/**
 * length - return length of string
 * @s: input string
 * Return: length of @s
 */
int length(char *s)
{
	if (s[0] != '\0')
		return (1 + length(s + 1));
	return (0);
}

/**
 * check_palindrome - funcition that checks palindrome
 * @s: string to check
 * @l: position of checking
 * Return: 1 if palindrome 0 otherwise
 */
int check_palindrome(char *s, int l)
{
	if (s[0] == '\0')
		return (1);
	if (s[0] == s[l - 1])
		return (check_palindrome(s + 1, l - 2));
	else
		return (0);
}
/**
 * is_palindrome - function that checks if a string is palindrome
 * @s: string to check
 * Return: 1 if @s is palindrome 0 otherwise
 */
int is_palindrome(char *s)
{
	int l;

	l = length(s);
	return (check_palindrome(s, l));
}
