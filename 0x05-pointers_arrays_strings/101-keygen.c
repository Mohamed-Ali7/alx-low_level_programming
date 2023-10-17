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
	"AaDFSE105w45S7ssbc3defghi7756j53kl@X77A57F257mnow7W5V4Gpqrst9uvw57sXzx11828xyz3ABCDEFGHIJKLMNO8P8QR4S19TU1VW2XYZ0123456789!@#$%&";
	srand(time(NULL));
	while (i < 100)
	{
		c = characters[rand() % (sizeof(characters) - 1)];
		putchar(c);
		i++;
	}
	return (0);
}
