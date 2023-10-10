#include "main.h"

/**
 * print_sign - prints (+) if the number > 0, (-) if it's < 0, or 0 if it's = 0
 * @n: is the number to check
 *
 * Return: 1 if the number > 0, 0 if it is = 0, and -1 it it is less than 0
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
