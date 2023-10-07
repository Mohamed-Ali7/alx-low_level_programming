#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	int n1 = '0';
	int n2 = '0';
	int n3 = '0';
	int n4 = '0';

	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '9')
		{
			n3 = n1;
			while (n3 <= '9')
			{
				n4 = n2 + 1;
				while (n4 <= '9')
				{
					putchar(n1);
					putchar(n2);
					putchar(' ');
					putchar(n3);
					putchar(n4);
					putchar(',');
					putchar(' ');
					n4++;
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
