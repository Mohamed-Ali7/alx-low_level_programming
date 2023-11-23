#include <stdio.h>

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Is the number to look into its bits
 * @index: Is the index of the bit
 * Return: The value of the bit in the given index
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long tmp = n;
	unsigned long x = 0;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (i == 0)
			x = 1;
		x *= 2;
	}
	if (x > n)
		return (-1);

	n = n ^ x;

	if (n != tmp)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
