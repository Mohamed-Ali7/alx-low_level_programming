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
	int num;
	int coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	num = atoi(argv[1]);
	while (num > 0)
	{
		if (num >= 25)
		{
			coins += num / 25;
			num %= 25;
		}
		else if (num >= 10)
		{
			coins += num / 10;
			num %= 10;
		}
		else if (num >= 5)
		{
			coins += num / 5;
			num %= 5;
		}
		else if (num >= 2)
		{
			coins += num / 2;
			num %= 2;
		}
		else
		{
			coins++;
			num %= 1;
		}
	}
	printf("%d\n", coins);
	return (0);
}
