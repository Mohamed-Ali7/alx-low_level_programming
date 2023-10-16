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

	while (i < 90)
	{
		c = (rand() % ( 128 - 48) + 48);
		putchar(c);
		i++;
	}
	return (0);
}
