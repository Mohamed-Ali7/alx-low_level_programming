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
	while (calc < 2645)
	{
		c = rand() % 128 ;
		putchar(c);
		calc += c;
	}
	return (0);
	putchar(2772 - clac);
}
