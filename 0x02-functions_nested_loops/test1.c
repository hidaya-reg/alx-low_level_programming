#include <stdio.h>

void main(void)
{
	long unsigned int hold1 = 1;
	long unsigned int hold2 = 2;
	long unsigned int current;
	
	printf("%lu, %lu, ", hold1, hold2);

	for (int i = 1; i < 49; i++)
	{
		current = hold1 + hold2;
		hold1 = hold2;
		hold2 = current;
		printf("%lu, ", current);

	}
	printf("\n");
}