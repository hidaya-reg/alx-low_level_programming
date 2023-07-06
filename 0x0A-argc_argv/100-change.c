#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 success, 1 otherwise
 */

int main(int argc, char *argv[])
{
	int i, amount, sum;
	int change[5];
	int rmain[5];
	int coin[5] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		amount = atoi(argv[1]);
		if (amount < 0)
		{
			printf("0\n");
			return (0);
		}
		else
		{
			change[0] = amount / coin[0];
			rmain[0] = amount - change[0] * coin[0];
			sum = change[0];
			for (i = 1; i <= 5; i++)
			{
				change[i] = rmain[i - 1] / coin[i];
				rmain[i] = rmain[i - 1] - change[i] * coin[i];
				sum += change[i];
				if (rmain[i] == 0)
					break;
			}
			printf("%d\n", sum);
			return (0);
		}
	}
}
