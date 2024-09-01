#include <stdio.h>
/**
 * main - sum even fibonacci numbers
 * Return: 0
 */

int main(void)
{
	unsigned long int hold1 = 1;
	unsigned long int hold2 = 2;
	unsigned long int current;
	unsigned long int sum = 2;

	while (sum < 4000000)
	{
		current = hold1 + hold2;
		hold1 = hold2;
		hold2 = current;
		if (current % 2 == 0)
		{
			sum += current;
		}
	}
	printf("%lu\n", sum);
	return (0);
}
