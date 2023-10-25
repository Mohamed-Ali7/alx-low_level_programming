#include "main.h"

/**
 * _strlen_recursion - returns the length of a string.
 * @s: Is the string calculate its length
 * Return: The length of string (s)
 */

int _strlen_recursion(char *s)
{
	int length = 1;

	if (*(s) == '\0')
	{
		return (0);
	}

	length += _strlen_recursion(s + 1);

	return (length);
}

