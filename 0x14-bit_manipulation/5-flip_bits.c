#include <stdio.h>
/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Is the number to look into its bits
 * @index: Is the index of the bit
 * Return: The value of the bit in the given index
 */

int get_bit(unsigned long int n, unsigned int index)
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

	if ((n & x) != 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * flip_bits - returns the number of bits you would need to
 * flip to get from one number to another.
 * @n: Is the first number
 * @m: Is the second number
 * Return: Number of flips
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long n_tmp = n;
	unsigned long m_tmp = m;
	int i = 0;
	int flips = 0;
	int n_index = 0;
	int m_index = 0;

	while (n_tmp != 0 || m_tmp != 0)
	{
		n_index = get_bit(n, i);
		m_index = get_bit(m, i);

		if (n_index == -1)
		{
			n_index = 0;
		}
		if (m_index == -1)
		{
			m_index = 0;
		}
		if (n_index != m_index)
		{
			flips++;
		}
		n_tmp = n_tmp >> 1;
		m_tmp = m_tmp >> 1;
		i++;
	}
	return (flips);
}
