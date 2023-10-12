#include "main.h"

/**
 * print_line - prints line using the character _ (n) times
 *@n: is the number of times the character _ should be printed
 * Return: void
 */
void print_line(int n)
{
	int counter = 0;

	while (counter < n)
	{
		_putchar('_');
		counter++;
	}
	_putchar('\n');
}
