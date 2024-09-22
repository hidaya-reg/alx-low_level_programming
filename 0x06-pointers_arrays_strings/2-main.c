#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char s1[98];
    char *ptr;
    int i;

    for (i = 0; i < 98 - 1; i++)
    {
        s1[i] = '*';
    }
    s1[i] = '\0';
    printf("first : %s\n", s1);
    printf("*****after copy 5 char function *****\n");
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 5);
    printf("first  : %s\n", s1);
    printf("result : %s\n", ptr);
    printf("*****after copy 90 char function *****\n");
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 90);
    printf("first  : %s", s1);
    printf("result : %s", ptr);
    for (i = 0; i < 98; i++)
    {
        if (i % 10)
        {
            printf(" ");
        }
        if (!(i % 10) && i)
        {
            printf("\n");
        }
        printf("0x%02x", s1[i]);
    }
    printf("\n");
    return (0);
}
