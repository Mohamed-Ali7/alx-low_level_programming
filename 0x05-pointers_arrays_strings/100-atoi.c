#include <stdio.h>

/**
 * _atoi - find digit numbers in a string and resturn them.
 * @s: is the string to search into
 * Return: the digit numbers;
 */
int _atoi(char *s)
{
	int i = 0;
	int minusChecker = 0;
	unsigned int integers = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			minusChecker++;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			integers *= 10;
			integers += (s[i] - '0');
		}else if (integers != 0 && !(s[i] >= 48 && s[i] <= 57))
		{
			break;
		}
		
		i++;
	}
	if (minusChecker % 2 != 0)
	{
		integers *= -1;
	}
	return (integers);
}
