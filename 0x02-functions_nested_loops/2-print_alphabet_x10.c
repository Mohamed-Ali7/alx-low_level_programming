#include "main.h"

/**
 * print_alphabet_x10 -  prints the alphabet characters 10 times in lowercase
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	char c;
	int counter = 0;

	while (counter < 10)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		counter++;
	}
}
