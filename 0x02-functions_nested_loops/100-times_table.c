#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the n times table, starting with 0.
 *@n: the number that times table will be printed
 * Return: void
 */
void print_times_table(int n)
{
	int counter = 0;
	int tableNums = 0;
	int repeat = 0;

	if (n < 0 || n > 15)
	{
		return;
	}
	while (counter <= n)
	{
		tableNums = 0;
		repeat = 0;
		while (repeat <= n)
		{
			printf("%d", tableNums);
		if (repeat != n)
		{
			printf(", ");
			if ((tableNums + counter) < 100)
			{
				printf(" ");
			}
			if ((tableNums + counter) < 10)
			{
				printf(" ");
			}
		}
		repeat++;
		tableNums += counter;
	}
		printf("\n");
		counter++;
	}
}
