#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void print_number(unsigned long n);

/**
 * _atoi - find digit numbers in a string and resturn them.
 * @s: is the string to search into
 * Return: the digit numbers;
 */
unsigned long _atoi(char *s)
{
	int i = 0;
	unsigned long integers = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && i == 0)
		{
			i++;
			continue;
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
	unsigned long result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];

	result = _atoi(num1) * _atoi(num2);
	if(num1[0] == '-' && num2[0] != '-')
	{
		_putchar('-');
	}
	if (num1[0] != '-' && num2[0] == '-')
	{
		_putchar('-');
	}
	print_number(result);
	return (0);
}

/**
 * print_number - prints an integer
 * @n: is the number to print
 *
 * Return: void
 */

void print_number(unsigned long n)
{
	unsigned long tmp = n;
	unsigned long divider = 1;

	while (n != 0)
	{
		n /= 10;
		if (n != 0)
		{
			divider *= 10;
		}
	}
	while (divider >= 1)
	{
		_putchar('0' + ((tmp / divider) % 10));
		divider /= 10;
	}
	_putchar('\n');
}
