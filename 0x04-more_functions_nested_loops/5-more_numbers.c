#include "main.h"

/**
 * more_numbers - print numbers from 0 to 14 10-times
 *
 * Return: void
 */
void more_numbers(void)
{
	int n = 0;
	int counter = 0;

	while (counter < 10)
	{
		n = 0;
		while (n <= 14)
		{
			if (n >= 10)
			{
				_putchar('0' + (n / 10));
			}
			_putchar('0' + (n % 10));
			n++;
		}
		_putchar('\n');
		counter++;
	}
}
