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
	while (calc < 3000)
	{
		c = rand() % 128 ;
		putchar(c);
		calc += c;
	}
	putchar(3127 - calc);
	return (0);
}
