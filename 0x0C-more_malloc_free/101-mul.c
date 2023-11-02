#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _atoi - find digit numbers in a string and resturn them.
 * @s: is the string to search into
 * Return: the digit numbers;
 */
unsigned long _atoi(char *s)
{
	int i = 0;
	int minusChecker = 0;
	unsigned long integers = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			minusChecker++;
		}
		else if (s[i] >= 48 && s[i] <= 57)
		{
			integers *= 10;
			integers += (s[i] - '0');
		}
		else
		{
			printf("Error\n");
			exit(98);
		}
		i++;
	}
	if (minusChecker % 2 != 0)
	{
		integers *= -1;
	}
	return (integers);
}
/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];

	printf("%ld\n", _atoi(num1) * _atoi(num2));
	return (0);
}
