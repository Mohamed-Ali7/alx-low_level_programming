#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string
 * @s: Is the string to calcualte its length
 * Return: The length of string (s)
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * _multiply - multiply two string numbers
 * @s1: the first number
 * @s2: the second number
 * Return: The result of multipling two numbers
 */
char *_multiply(char *s1, char *s2)
{
	char *rst;
	int s1Len, s2Len, b, c, j, x;

	s1Len = _strlen(s1);
	s2Len = _strlen(s2);
	j = x = s1Len + s2Len;
	rst = malloc(s1Len + s2Len);
	if (rst == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	while (j >= 0)
		rst[j--] = 0;

	for (s1Len--; s1Len >= 0; s1Len--)
	{
		if (!(s1[s1Len] >= 48 && s1[s1Len] <= 57))
		{
			free(rst);
			printf("Error\n"), exit(98);
		}
		j = s1[s1Len] - '0';
		c = 0;
		for (s2Len = _strlen(s2) - 1; s2Len >= 0; s2Len--)
		{
			if (!(s2[s2Len] >= 48 && s2[s2Len] <= 57))
			{
				free(rst);
				printf("Error\n"), exit(98);
			}
			b = s2[s2Len] - '0';
			c += rst[s1Len + s2Len + 1] + (j * b);
			rst[s1Len + s2Len + 1] = c % 10;
			c /= 10;
		}
		if (c)
			rst[s1Len + s2Len + 1] += c;
	}
	return (rst);
}


/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *result;
	int j;
	int i;
	int x;
	int arg1Len;
	int arg2Len;

	if (argc != 3)
	{
		printf("Error\n"), exit(98);
	}

	arg1Len = _strlen(argv[1]);
	arg2Len = _strlen(argv[2]);
	x = arg1Len + arg2Len;
	result = _multiply(argv[1], argv[2]);
	j = 0;
	for (i = 0; i < x; i++)
	{
		if (result[i])
		{
			j = 1;
		}
		if (j)
		{
			_putchar(result[i] + '0');
		}
	}
	if (!j)
	{
		_putchar('0');
	}
	_putchar('\n');
	free(result);
	return (0);
}
