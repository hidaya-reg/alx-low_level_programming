#include <stdio.h>
/**
 * main - Entry point
 * Return: 0 prints the name of the file it was compiled from
 */

int main(void)
{
	printf("%s\n", __BASE_FILE__);
	return (0);
}
