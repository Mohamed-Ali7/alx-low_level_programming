#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;
	int r;
	int num = 0;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		r = 0;
		num = 0;
		while (argv[i][r] != '\0')
		{
			if (argv[i][r] < 48 || argv[i][r] > 57)
			{
				printf("Error\n");
				return (1);
			}
			num = (num * 10) + (argv[i][r] - 48);
			r++;
		}
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}

