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
	char characters[] =
	"aDFSEssbcdefghijklmnowWVGpqrstuvwsXzxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
	srand(time(NULL));
	while (i < 100)
	{
		c = characters[rand() % (sizeof(characters) - 1)];
		putchar(c);
		i++;
	}
	return (0);
}
