/**
 * _atoi - function that convert a string to an integer
 * @s: string to convert to integer
 * Return: integer (converted string
 */

int _atoi(char *s)
{
	int i, sign;
	unsigned int r;
	int boolean;

	i = 0;
	sign = 1;
	boolean = 0;
	r = 0;
	while (*(s + i))
	{
		if (*(s + i) == 45)
			sign *= -1;
		while (*(s + i) <= 57 && *(s + i) >= 48)
		{
			boolean = 1;
			r = (r * 10) + *(s + i) - '0';
			i++;
		}
		if (boolean == 1)
			break;
		i++;
	}
	r *= sign;
	return (r);

}
