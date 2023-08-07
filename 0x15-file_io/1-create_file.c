#include "main.h"

/**
 * create_file - creates new file
 * @filename: name of the file to create
 * @text_content: string to write to the file
 * Return: 1 on success
 * -1 if file cannot be created, written or filename is NULL
 *  create empty file if text_content is NULL
 */

int create_file(const char *filename, char *text_content)
{
	int fd, len_txt, len_wr;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	for (len_txt = 0; text_content[len_txt]; len_txt++)
		;

	len_wr = write(fd, text_content, len_txt);

	if (close(fd) == -1 || len_txt != len_wr)
		return (-1);
	return (1);
}
