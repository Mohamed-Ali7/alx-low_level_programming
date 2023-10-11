#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n1 = 1;
	unsigned long n2 = 2;
	unsigned long result = 0;
	int counter = 0;

	while (counter < 98)
	{
		printf("%lu", n1);
		if (counter != (98 - 1))
		{
			printf(", ");
		}
		result = n1 + n2;
		n1 = n2;
		n2 = result;
		counter++;
	}
	printf("\n");
	return (0);
}
