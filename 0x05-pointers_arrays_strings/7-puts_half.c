#include "main.h"

/**
 * void puts_half - prints half of a string, followed by a new line.
 * @str: is the string to print
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int middle;

	while (str[length] != '\0')
	{
		length++;
	}
	
	middle = length / 2;

	while (middle < length)
	{
		_putchar(str[middle]);
		middle++;
	}
	_putchar('\n');
}

