/**
 * prime_number - check for at least one multiplier
 * @n: input to check for multiplier
 * @i: potential multiplier
 * Return: 1 if @n is prime number 0 otherwise
 */

int prime_number(int n, int i)
{
	if (n == i)
		return (1);
	if (n % i == 0)
		return (0);
	else
		return (prime_number(n, i + 1));
}

/**
 * is_prime_number - function that check for prime number
 * @n: input to check if its a prime number
 * Return: 1 if @n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (prime_number(n, 2));
}
