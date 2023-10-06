#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	int n1 = '0';
	int n2 = '1';
	int n3 = '2';

	while (n1 <= '9')
	{
		n2 = n1 + 1;
		while (n2 <= '9')
		{
			n3 = n2 + 1;
			while (n3 <= '9')
			{
				putchar(n1);
				putchar(n2);
				putchar(n3);
				if (n1 != (n2 - 1) || n2 != (n3 - 1) || n3 != '9')
				{
					putchar(',');
					putchar(' ');
				}
				n3++;
			}
			n2++;
		}
		n1++;
	}
	putchar('\n');
	return (0);
}
