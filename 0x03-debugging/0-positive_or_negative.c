#include <stdio.h>

/**
 * positive_or_negative - checks if an integer is positive or negative
 * @n: is the number to check
 * Return: void
 */

void positive_or_negative(int n)
{
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else
	{
		printf("%d is negative\n", n);
	}
}
