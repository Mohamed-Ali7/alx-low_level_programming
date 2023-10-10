#include "main.h"

/**
 * jack_bauer -  prints every minute of the day
 *
 * Return: void
 */
void jack_bauer(void)
{
	int hours = 0;
	int minutes = 0;

	while (hours < 24)
	{
		minutes = 0;
		while (minutes < 60)
		{
			_putchar('0' + (hours / 10));
			_putchar('0' + (hours % 10));
			_putchar(':');
			_putchar('0' + (minutes / 10));
			_putchar('0' + (minutes % 10));
			_putchar('\n');
			minutes++;
		}
		hours++;
	}
}
