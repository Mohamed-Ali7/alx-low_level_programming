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
	int num1 = 0;
	int num2 = 0;
	int result = 1;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	for (i = 1; i < argc; i++)
	{
		r = 0;
		while (argv[i][r] != '\0')
		{
			if (argv[i][r] == '-')
			{
				result *= -1;
				r++;
				continue;
			}
			if (i == 1)
			{
				num1 = (num1 * 10) + (argv[i][r] - 48);
			}
			else
			{
				num2 = (num2 * 10) + (argv[i][r] - 48);
			}
			r++;
		}
	}
	printf("%d\n", num1 * num2 * result);
	return (0);
}

