#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Return: is 0 (Success)
 */

int main(void)
{
	int n = 97;

	while (n <= 122)
	{
		printf("%c", n);
		n++;
	}
	printf("\n");
	return (0);
}
