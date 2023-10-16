#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Retrun: 0 
 */
int main(void)
{
	int i = 0;
	char c;

	while (i < 100)
	{
		c = rand() % 128;
		putchar(c);
		i++;
	}
	return (0);
}
