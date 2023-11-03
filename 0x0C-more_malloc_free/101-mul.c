#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int _strlen(char *s);
char *multiply(char *s1, char *s2);
/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	char *result, *num1, *num2;
	int resultLen, num1Len, num2Len;
	int i = 0;
	int r = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = argv[1];
	num2 = argv[2];
	while (num1[i] != '\0' || num2[r] != '\0')
	{
		if (num1[i] != '\0')
		{
			if (!(num1[i] >= '0' && num1[i] <= '9'))
			{
				printf("Error\n");
				exit(98);
			}
			i++;
		}
		if (num2[r] != '\0')
		{
			if (!(num2[r] >= '0' && num2[r] <= '9'))
			{
				printf("Error\n");
				exit(98);
			}
			r++;
		}
	}
	num1Len = _strlen(num1);
	num2Len = _strlen(num2);
	if (num1Len == 0 || num2Len == 0)
	{
		printf("Error\n");
		exit(98);
	}
	resultLen = num1Len + num2Len;
	if (num1Len > num2Len)
	{
		result = multiply(num1, num2);
	}
	else
	{
		result = multiply(num1, num2);
	}
	i = 0;
	r = 0;
	while (i < resultLen)
	{
		if (result[i] != '\0')
		{
			r = 1;
		}
		if (r == 1)
		{
			_putchar(result[i] + '0');
		}
		i++;
	}
	if (r == 0)
	{
		_putchar('0');
	}
	_putchar('\n');
	free(result);
	return (0);
}

/**
 * multiply - Receives two string numbers and multiply them
 * @s1: Is the main number that the sub number will be multiplied to
 * @s2: Is the sub number that will be multiplied to the main number
 * Return: A pointer to a string that contains
 * the result of multipling the two string numbers
 */

char *multiply(char *s1, char *s2)
{
	int resultLen;
	char *result;
	int l1, l2, i, r, tmpR, numR;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	resultLen = l1 + l2;
	i = resultLen;
	result = malloc(resultLen);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}
	while (i--)
	{
		result[i] = 0;
	}

	for (i = l1 - 1; i >= 0; i--)
	{
		numR = 0;

		for (r = l2 - 1; r >= 0; r--)
		{
			tmpR = (s1[i] - '0') * (s2[r] - '0');
			numR += result[i + r + 1] + tmpR;
			result[i + r + 1] = numR % 10;
			numR /= 10;
		}
		if (numR > 0)
			result[i + r + 1] += numR;
	}
	return (result);
}

/**
 * _strlen - cout length of the received string
 * @s: is the string to return its length
 * Return: the length of the received string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
