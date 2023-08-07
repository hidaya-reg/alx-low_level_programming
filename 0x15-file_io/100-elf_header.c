#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * _strncmp - ffct compares twos strings
 * @s1: firdt string
 * @s2: second string
 * Return: 0 if n bytes of s1 and s2 are equal, 0 otherwise
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i, r;

	for (i = 0; n && s1[i] != '\0' && s2[i] != '\0'; i++, n--)
	{
		r = s1[i] - s2[i];
		if (r != 0)
			break;
	}
	return (r);
}

/**
 * _magic - prit Magic
 * @buf: elf header
 */

void _magic(const char *buf)
{
	int i;

	if (_strncmp((const char *) buf, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an elf file\n", 23);
		exit(98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", buf[i]);
	printf("\n");
}

int main(int ac, char *av[])
{
	char buf[18];
	int fd;

	if (ac != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_name\n", 31);
		exit(98);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: Can't read file\n", 23);
		exit(98);
	}

	read(fd, buf, 18);
	_magic(buf);
	close(fd);
	return (0);
}
