#include "main.h"

/**
 * print_most_numbers - prints number from 0 to 9 except  2 and 4
 * Return: void
 */

void print_most_numbers(void)
{
	int n = 0;

	while (n <= 9)
	{
		if (n == 2 || n == 4)
		{
			n++;
			continue;
		}
		_putchar('0' + n);
		n++;
	}
	_putchar('\n');
}
