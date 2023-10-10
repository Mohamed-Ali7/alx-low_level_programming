#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 *@n: is the number where the count will start from
 * Return: void
 */
void print_to_98(int n)
{
	while (n <= 98)
	{
		if (n >= 10)
		{
			_putchar('0' + (n / 10));
		}
		if (n < 0)
		{
			_putchar('-');
			if (n <= -10)
			{
				_putchar('0' + ((n / 10) * -1));
			}
			_putchar('0' + ((n % 10) * -1));
		}
		else
		{
			_putchar('0' + (n % 10));
		}
		if (n != 98)
		{
			_putchar(',');
			_putchar(' ');
		}
		n++;
	}
	_putchar('\n');
}
