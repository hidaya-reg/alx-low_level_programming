#include "main.h"

/**
 * append_text_to_file - append text at the end of file
 * @filename: name of the file
 * @text_content: string to add at the end of file
 * Return: 1 success, 0 failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len_wr, len_txt;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
		return (-1);
	if (text_content == NULL)
		return (1);

	for (len_txt = 0; text_content[len_txt]; len_txt++)
		;
	len_wr = write(fd, text_content, len_txt);
	close(fd);
	if (len_txt != len_wr)
		return (-1);
	return (1);
}
