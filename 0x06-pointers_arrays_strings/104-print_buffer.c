#include <stdio.h>

/**
 * print_buffer - prints a buffer.
 * @b: is the buffer (string) to print
 * @size: is the number of bytes that it will be printed
 * Return: void
 */

void print_buffer(char *b, int size)
{
	int i = 0;
	char tmp[10];
	int x = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	while (i < size)
	{
		printf("%08x: ", i);
		for (x = 0; x < 10; x++)
		{
			if (x % 2 == 0 && x > 0)
			{
				printf(" ");
			}
			if (i < size)
			{
				printf("%02x", b[i]);
				if (b[i] >= 32 && b[i] <= 126)
				{
					tmp[x] = b[i];
				}
				else
				{
					tmp[x] = '.';
				}
			}
			else
			{
				printf("  ");
				tmp[x] = '\0';
			}
			i++;
		}
		printf(" %s\n", tmp);
	}
}
