#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal.
 *@n: is the number of times the character \ should be printed
 * Return: void
 */
void print_diagonal(int n)
{
	int counter = 0;
	int repeat = 0;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	while (counter < n)
	{
		repeat = counter;
		while (repeat > 0)
		{
			_putchar(' ');
			repeat--;
		}
		_putchar('\\');
		_putchar('\n');
		counter++;
	}
}
