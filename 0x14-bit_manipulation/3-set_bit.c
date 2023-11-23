#include <stdio.h>

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Is the value to look into its bits
 * @index: Is the index of the bit
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long x = 0;
	unsigned int i;
	unsigned int bits = sizeof(unsigned long int) * 8;

	if (bits < index)
	{
		return (-1);
	}
	for (i = 0; i <= index; i++)
	{
		x = 1 << i;
	}

	*n = *n | x;
	return (1);
}
