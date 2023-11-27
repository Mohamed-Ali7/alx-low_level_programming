#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * create_file - Creates a file.
 * @filename: Is the name of the file to create
 * @text_content: Is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int n;
	int fd;
	int len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT, 0600);

	if (text_content == NULL)
	{
		return (1);
	}
	while (text_content[len] != '\0')
	{
		len++;
	}
	if (fd == -1)
	{
		return (-1);
	}
	n = write(fd, text_content, len);

	if (n == -1)
	{
		return (-1);
	}

	close(fd);
	return (1);
}
