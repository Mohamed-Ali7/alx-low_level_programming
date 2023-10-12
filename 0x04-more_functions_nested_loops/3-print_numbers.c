#include "main.h"

/**
 * print_numbers - print numbers from 0 to 9
 *
 * Return: void
 */
void print_numbers(void)
{
	int n = 0;

	while (n <= 9)
	{
		_putchar('0' + n);
		n++;
	}
	_putchar('\n');
}
