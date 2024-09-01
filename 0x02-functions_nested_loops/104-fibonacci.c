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
	int i = 0;
	int tens = 10;

	printf("%lu, %lu, ", hold1, hold2);
	while (i < 15)
	{
		current = hold1 + hold2;
		hold1 = hold2;
		hold2 = current;

		while ((current / tens) > 10)
		{
			tens *= 10;
		}
		if ((current / tens) == 1 || (current / tens) == 2)
		{
			printf("%lu", current);
			if (i != )
		}
		i++;
	}
	printf("\n");
	return (0);
}