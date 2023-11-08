#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;
	int byteNum;
	char *result = (char *) main;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	byteNum = atoi(argv[1]);

	if (byteNum < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < byteNum; i++)
	{
		printf("%02x", (unsigned char) result[i]);
		if (i != byteNum - 1)
		{
			printf(" ");
		}
	}

	printf("\n");
	return (0);
}
