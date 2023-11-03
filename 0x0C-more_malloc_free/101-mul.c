#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *multiply(char *mainNum, char *subNum, int mainNLen, int subNLen);
/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *result, *num1, *num2;
	int num1Len, num2Len;
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
	num1Len = strlen(num1);
	num2Len = strlen(num2);
	if (num1Len > num2Len)
	{
		result = multiply(num1, num2, num1Len, num2Len);
	}
	else
	{
		result = multiply(num2, num1, num2Len, num1Len);
	}
	i = 0;
	while (result[i] == '0')
	{
		i++;
	}
	while (result[i] != '\0')
	{
		_putchar(result[i]);
		i++;
	}
	_putchar('\n');
	free(result);
	return (0);
}

/**
 * multiply - Receives two string numbers and multiply them
 * @mainNum: Is the main number that the sub number will be multiplied to
 * @subNum: Is the sub number that will be multiplied to the main number
 * @mainNLen: Is the length of the main number
 * @subNLen: Is the length of the sub number
 * Return: A pointer to a string that contains
 * the result of multipling the two string numbers
 */

char *multiply(char *mainNum, char *subNum, int mainNLen, int subNLen)
{
	int resultLen = mainNLen + subNLen;
	char *result = malloc(mainNLen + subNLen);
	int i = resultLen;
	int mulReminder, sumReminder;
	int r, tmpR, numR;

	while (i >= 1)
	{
		result[i - 1] = '0';
		i--;
	}
	for (i = subNLen - 1; i >= 0; i--)
	{
		mulReminder = 0;
		sumReminder = 0;
		for (r = mainNLen - 1; r >= 0; r--)
		{
			tmpR = (subNum[i] - 48) * (mainNum[r] - 48) + mulReminder;

			numR = (result[i + r + 1] - 48) + (tmpR % 10);
			result[i + r + 1] = ((numR + sumReminder) % 10) + 48;

			sumReminder = (numR + sumReminder) / 10;
			mulReminder = tmpR / 10;
			if (r == 0 && (mulReminder > 0 || sumReminder > 0))
			{

				result[i + r] = (mulReminder + sumReminder) + 48;
			}
		}
	}
	return (result);
}
