#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line.
 *@size: is the size of the triangle
 * Return: void
 */
void print_triangle(int size)
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
		repeat = size;
		while (repeat > 0)
		{
			if (repeat > (counter + 1))
			{
				_putchar(' ');
			}
			else
			{
				_putchar('#');
			}
			repeat--;
		}
		_putchar('\n');
		counter++;
	}
}
