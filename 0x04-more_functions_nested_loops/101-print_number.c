#include "main.h"
#include <stdio.h>
/**
 * print_number - prints an integer
 * @n: is the number to print
 *
 * Return: void
 */
void print_number(int n)
{
	long tmp = n;
	long divider = 1;

	if (n < 0)
	{
		tmp *= -1;
		_putchar('-');
	} 

	while (n != 0)
	{
		divider *= 10;
		n /= 10;
	}
	divider /= 10;
	while (divider >= 10)
	{
		_putchar('0' + ((tmp / divider) % 10));
		divider /= 10;
	}
	_putchar('0' + (tmp % 10));
}
