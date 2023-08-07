#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	int file_from, file_to, len_src, len_dest;
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
	char buf[BUFSIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	file_from = open(av[1], O_RDONLY);
	if (file_from < 0)
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", av[1]), exit(98);

	file_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, perm);
	if (file_to < 0)
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", av[2]), exit(99);

	len_src = 1;
	while (len_src)
	{
		len_src = read(file_from, buf, BUFSIZE);
		if (len_src < 0)
			dprintf(STDERR_FILENO, "Error: can't read from file %s\n", av[1]), exit(98);
		if (len_src > 0)
		{
			len_dest = write(file_to, buf, len_src);
			if (len_src != len_dest || len_dest < 0)
				dprintf(STDERR_FILENO, "Error: can't write to %s\n", av[2]), exit(99);
		}
	}
	if (close(file_from) < 0)
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_from), exit(100);
	if (close(file_to) < 0)
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_to), exit(100);
	return (0);
}
