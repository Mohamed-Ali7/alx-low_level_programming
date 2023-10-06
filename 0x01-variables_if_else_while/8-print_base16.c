#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	int n = '0';
	char x = 'a';

	while (n <= '9' || x <= 'f')
	{
		if (n <= '9')
		{
			putchar(n);
			n++;
		}
		else
		{
			putchar(x);
			x++;
		}
	}
	putchar('\n');
	return (0);
}
