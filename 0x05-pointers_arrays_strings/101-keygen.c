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
	while (calc < 100)
	{
		c = rand() % 128;
		calc ++;
		putchar(c);
	}
	return (0);
}
