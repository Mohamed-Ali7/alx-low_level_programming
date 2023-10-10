#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
 *
 * Return: void
 */
void times_table(void)
{
	int counter = 1;
	int tableNums = 0;
	int repeat = 0;

	while (counter < 10)
	{
		tableNums = 0;
		repeat = 0;
		while (repeat < 10)
		{
			if (tableNums >= 10)
			{
				_putchar('0' + (tableNums / 10));
			}
			_putchar('0' + (tableNums % 10));
			_putchar(',');
			_putchar(' ');
			if ((tableNums + counter) < 10)
			{
				_putchar(' ');
			}
			repeat++;
			tableNums += counter;
		}
		_putchar('\n');
		counter++;
	}
}
