/**
 * sqrt_root - function that return sqrt of n
 * @n: number
 * @guess: first guess of square root
 * Return: root of @n
 */

int sqrt_root(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess < n)
		return (sqrt_root(n, guess + 1));
	else
		return (-1);
}
/**
 * _sqrt_recursion - function that returns the natural square
 * root of a number
 * @n: number to return its square root
 * Return: square root of @n
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (sqrt_root(n, 2));
}

