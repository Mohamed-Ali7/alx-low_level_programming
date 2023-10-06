#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	int n = 97;
	int x = 65;

	while (n <= 122 || x <= 90)
	{
		if (n <= 122)
		{
			printf("%c", n);
			n++;
		}
		else
		{
			printf("%c", x);
			x++;
		}
	}
	printf("\n");
	return (0);
}
