#include "main.h"

/**
 * largest_number - returns the largest of 3 numbers
 * @a: first integer
 * @b: second integer
 * @c: third integer
 * Return: largest number
 */

int largest_number(int a, int b, int c)
{
	int largest;

	if (a > b)
	{
		if (c > a)
		{
			largest = c;
		}
		else
		{
			largest = a;
		}
	}
	else if (a > c)
	{
		if (b > c)
		{
			largest = b;
		}
		else
		{
			largest = a;
		}
	}
	else
	{
		if (b >= c)
		{
			largest = b;
		}
		else if (c >= b)
		{
			largest = c;
		}
	}

	return (largest);
}
