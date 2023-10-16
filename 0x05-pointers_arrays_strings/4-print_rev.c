#include "main.h"

/**
 * print_rev -  prints a string, in reverse, followed by a new line.
 * @s: is the string to print reversed
 * Return: void
 */

void print_rev(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	while (length >= 0)
	{
		_putchar(s[length]);
		length--;
	}
}
