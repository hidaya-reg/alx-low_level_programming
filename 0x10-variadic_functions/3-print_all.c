#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_integer - print integer
 * @args: list of parameters
 * Return: void
 */

void print_integer(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_char - print char
 * @args: list of parameters
 * Return: void
 */

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_str - print string
 * @args: list of parameters
 * Return: void
 */

void print_str(va_list args)
{
	char *str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}

/**
 * print_float - print float
 * @args: list of arguments
 * Return: void
 */

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_all - function that prints anything
 * @format: list of typrs of arguments
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i, j;
	char *sep;
	arg_type map_type[] = {
		{"c", print_char},
		{"i", print_integer},
		{"f", print_float},
		{"s", print_str},
		{NULL, NULL}
	};

	va_start(args, format);
	i = 0;
	sep = "";
	while (format != NULL && format[i] != '\0')
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == *(map_type[j]).format)
			{
				printf("%s", sep);
				map_type[j].function(args);
				sep = ", ";
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
