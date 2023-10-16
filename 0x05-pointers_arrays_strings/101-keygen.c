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
	int i = 0;
	char c;
	
	srand(time(NULL));
	while (i < 50)
	{
		c = (rand() % ( 128 - 48) + 48);
		putchar(c);
		i++;
	}
	srand(time(NULL));
	return (0);
}
