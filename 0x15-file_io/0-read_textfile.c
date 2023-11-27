#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * read_textfile - Reads text file and prints it to the POSIX standard output
 * @filename: Is the name of the file to read
 * @letters: Is the number of letters it should read and print
 * Return: The actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n;
	char *str;

	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		return (0);
	}

	str = malloc(sizeof(char) * letters);

	n = read(fd, str, letters);
	if (n == -1)
	{
		free(str);
		return (0);
	}
	if (write(STDOUT_FILENO, str, n) == -1)
	{
		free(str);
		return (0);
	}
	close(fd);
	free(str);
	return (n);
}
