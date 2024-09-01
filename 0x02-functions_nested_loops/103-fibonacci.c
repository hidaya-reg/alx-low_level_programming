#include <stdio.h>
/**
 * main - sum even fibonacci numbers
 */

int main(void)
{
	long unsigned int hold1 = 1;
	long unsigned int hold2 = 2;
	long unsigned int current;
	long unsigned int sum = 2;

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
