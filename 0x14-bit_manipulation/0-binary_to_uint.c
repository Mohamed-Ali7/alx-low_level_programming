#include <math.h>
#include <stddef.h>

unsigned int _pow(unsigned int num, unsigned int pow_num);
/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Is the binary number to convert
 * Return: the converted number, or 0 if there is one or more chars
 * in the string b that is not 0 or 1
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int result = 0;
	unsigned int x = 0;
	int len = 0;

	if (b == NULL || b[0] == '\0')
	{
		return (0);
	}
	for (i = 0; b[i] != '\0'; i++)
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}
		if (b[i] != '0')
		{
			result += _pow(2, x);
		}
		x++;
	}
	return (result);
}

/**
 * _pow - Calculates the power of a number
 * @num: Is the number to get its power
 * @pow_num: Is the power that the number will be raised to
 * Return: The number after  raised to the received power
 */
unsigned int _pow(unsigned int num, unsigned int pow_num)
{
	unsigned int i;
	int r = num;

	if (pow_num == 0)
	{
		return (1);
	}
	for (i = 1; i < pow_num; i++)
	{
		r *= num;
	}
	return (r);
}
