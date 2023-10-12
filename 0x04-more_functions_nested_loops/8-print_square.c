#include "main.h"

/**
 * print_square - prints a square, followed by a new line.
 *@size: is the size of the square
 * Return: void
 */
void print_square(int size)
{
	int counter = 0;
	int repeat = 0;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	while (counter < size)
	{
		repeat = 0;
		while (repeat < size)
		{
			_putchar('#');
			repeat++;
		}
		_putchar('\n');
		counter++;
	}
}
