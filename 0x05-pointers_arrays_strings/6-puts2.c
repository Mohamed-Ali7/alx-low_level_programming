#include "main.h"

/**
 * puts2 -  prints every other character, starting with the first character
 * @str: is the string to print
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\0')
		{
			break;
		}
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
}
