#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Retrun: 0 
 */

void shuffle(char *array, size_t n) {
	if (n > 1)
       	{
		size_t i;
		for (i = 0; i < n - 1; i++) {
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			char t = array[j];
			array[j] = array[i];
			array[i] = t;
		}	
	}
}

int main(void)
{
	int i = 0;
	char c;
	char characters[] =
	"AaDFSE105w45S7ssbc3defghi7756j53kl@X77A57F257mnow7W5V4Gpqrst9uvw57sXzx11828xyz3ABCDEFGHIJKLMNO8P8QR4S19TU1VW2XYZ0123456789!@#$%&";
	srand(time(NULL));
	shuffle(characters, sizeof(characters) - 1);

	while (i < 100)
	{
		c = characters[rand() % (sizeof(characters) - 1)];
		putchar(c);
		i++;
	}
	return (0);
}
