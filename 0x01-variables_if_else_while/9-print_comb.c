#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	char n = '0';

	while (n <= '9')
	{
		putchar(n);
		if(n != '9')
		{
			putchar(',');
			putchar(' ');
		}
		n++;
	}
	putchar('\n');
	return (0);
}
