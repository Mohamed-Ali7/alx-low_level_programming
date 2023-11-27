#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void copy_file(char *source, char *target);
/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	copy_file(argv[1], argv[2]);
	return (0);
}

/**
 * copy_file - Copies the content of a file to another file.
 * @source: Is the file to copy from
 * @target: Is the target file to copy to
 * Return: void
 */
void copy_file(char *source, char *target)
{
	int n, source_fd, target_fd, buf_size = 1024;
	char buffer[1024];

	source_fd = open(source, O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		exit(98);
	}

	target_fd = open(target, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (target_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", target);
		exit(99);
	}

	while (buf_size == 1024)
	{
		buf_size = read(source_fd, buffer, 1024);

		if (buf_size == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
			exit(98);
		}
		n = write(target_fd, buffer, buf_size);
		if (n == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", target);
			exit(99);
		}
	}
	n = close(source_fd);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}
	n = close(target_fd);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", target_fd);
		exit(100);
	}

}
