#include "main.h"
#include <fcntl.h>

/**
 * read_textfile - read a text file and print it to stdout
 * @filename: name of textfile
 * @letters: number of letters should read and print
 * Return: actual number of letters read, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, len_rd, len_wr;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		free(buf);
		return (0);
	}

	len_rd = read(fd, buf, letters);

	if (len_rd < 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	len_wr = write(STDOUT_FILENO, buf, len_rd);

	free(buf);
	close(fd);

	if (len_wr != len_rd)
		return (0);

	return (len_rd);
}
