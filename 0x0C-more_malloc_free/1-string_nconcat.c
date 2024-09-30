#include <stdlib.h>
/**
 * string_nconcat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from @s2 to concatenate
 * Return: pointer pointing to a newly allocated space in memory
 * which contains @s1 followed by n bytes of s2
 * if @s2 equal to NULL, treat it as an empty string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int len1, len2, m, i;

	m = n;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (*(s1 + len1) != '\0')
		len1++;
	len2  = 0;
	while (*(s2 + len2) != '\0')
		len2++;

	if (n >= len2)
		m = len2;

	p = malloc(sizeof(char) * (len1 + m) + 1);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		p[i] = s1[i];

	for (i = 0; i < m; i++)
		p[len1 + i] = s2[i];
	p[len1 + i] = '\0';

	return (p);
}
/*
int length(char *s)
{
    int l = 0;
    while (s && s[l])
    {
        l++;
    }
    return l;
}
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    int l1, l2, m;
    char *result;

    l1 = (s1 == NULL)? 0 : length(s1);
    
    l2 = (s2 == NULL)? 0 : length(s2);
    
    m = (n >= l2)? l2 : n;
    
    result = malloc(sizeof(char) * (l1 + m + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < l1; i++)
        result[i] = s1[i];
    for (int j = 0; j < n; j++)
        result[l1 + j] = s2[j];
    result[l1 + m] = '\0';
    return result;
}
*/
