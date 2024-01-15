#include "main.h"

/**
 * _isalpha -  checks whether the character is in lowercase or uppercase
 * @c: is the character to check
 *
 * Return: 1 if the character is in lowercase or uppercase  and 0 if it is not
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
