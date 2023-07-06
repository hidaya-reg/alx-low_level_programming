/**
 * reverse_array - function that reverses the content of an array of integers
 * @a: an array of integers
 * @n: number of elements of a
 * Return: void array a is reversed
 */

void reverse_array(int *a, int n)
{
	int i, tmp;

	for (i = 0; i < (n - 1) / 2; i++)
	{
		tmp = *(a + i);
		*(a + i) = *(a + n - 1 - i);
		*(a + n - i - 1) = tmp;
	}
}
