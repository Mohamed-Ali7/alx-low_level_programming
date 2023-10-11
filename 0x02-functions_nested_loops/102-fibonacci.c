#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int n1 = 1;
	int n2 = 2;
	int result = 0;
	int counter = 0;

	while (counter < 50)
	{
		printf("%d", n1);
		if (counter != (50 - 1))
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
