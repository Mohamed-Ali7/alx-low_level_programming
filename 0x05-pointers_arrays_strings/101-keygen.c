#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Retrun: 0 
 */

int main(void)
{
	int calc = 0;
	char c;
	srand(time(NULL));
	while (calc < 40)
	{
		c = (rand() % (128 - 1 + 1)) + 1;
		putchar(c);
	}
	return (0);
}
