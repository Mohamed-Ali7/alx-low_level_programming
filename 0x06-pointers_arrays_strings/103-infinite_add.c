#include <stdio.h>

void sum(int s1Len, int s2Len, char *s1, char *s2, char *bf, int *bfLen);

/**
 * *infinite_add - adds two string numbers.
 * @n1: is the first string to add
 * @n2: is the second string to add
 * @r: is the buffer that the function will use to store the result
 * @size_r: is the lengths of the buffer
 * Return: a pointer to the resulting string
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i1 = 0;
	int i2 = 0;
	int counter = 0;
	int tmpSize = size_r;

	while (n1[i1] != '\0' || n2[i2] != '\0')
	{
		if (n1[i1] != '\0')
		{
			i1++;
		}
		if (n2[i2] != '\0')
		{
			i2++;
		}
	}

	if (i1 >= (size_r - 1) || i2 >= (size_r - 1))
	{
		return (0);
	}
	i1--;
	i2--;

	sum(i1, i2, n1, n2, r, &size_r);

	while (size_r <= tmpSize)
	{
		r[counter] = r[size_r];
		size_r++;
		counter++;
	}

	r[counter] = '\0';
	return (r);
}

/**
 * sum - a helper function to add two string numbers.
 * @s1: is the first string to add
 * @s2: is the second string to add
 * @s1Len: is the lengths of the first String number
 * @s2Len: is the lengths of the second String number
 * @bf: is the buffer that the function will use to store the result
 * @bfLen: is the lengths of the buffer
 * Return: void
 */
void sum(int s1Len, int s2Len, char *s1, char *s2, char *bf, int *bfLen)
{
	int reminder = 0;
	int result = 0;

	while (s1Len >= 0 || s2Len >= 0)
	{
		if (s1Len < 0)
		{
			result = (s2[s2Len] - 48) + reminder;
		}
		else if (s2Len < 0)
		{
			result = (s1[s1Len] - 48)  + reminder;
		}
		else
		{
			result = ((s1[s1Len] - 48) + (s2[s2Len] - 48)) + reminder;
		}
		reminder = result / 10;
		if (s1Len <= 0 && s2Len <= 0)
		{
			if (result >= 10)
			{
				bf[*bfLen] = (result % 10) + 48;
				*bfLen = *bfLen - 1;
				bf[*bfLen] = (result / 10) + 48;
			}
			else
			{
				bf[*bfLen] = (result % 10) + 48;
			}
			break;
		}
		else
		{
			bf[*bfLen] = (result % 10) + 48;
		}
		*bfLen = *bfLen - 1;
		s1Len--;
		s2Len--;
	}
}
