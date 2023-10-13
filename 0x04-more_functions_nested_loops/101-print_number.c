#include "main.h"

/**
 * print_number - prints an integer
 * @n: is the number to print
 *
 * Return: void
 */
void print_number(int n)
{
	int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = num * -1;
	}
	if ((num / 10) > 0)
	{
		print_number(num / 10);
	}
	_putchar('0' + (num % 10));
}
