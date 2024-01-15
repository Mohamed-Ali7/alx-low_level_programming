#include "main.h"

/**
 * _islower -  checks whether the character is in lowercase or not
 * @c: is the character to check
 *
 * Return: 1 if the character is lower and 0 if it is not
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
