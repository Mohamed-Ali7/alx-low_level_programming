#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	long n1 = 1;
	long n2 = 2;
	long result = 0;
	long sum = 0;

	while (result <= 4000000)
	{
		if ((n2 % 2) == 0)
		{
			sum += n2;
		}
		result = n1 + n2;
		n1 = n2;
		n2 = result;
	}
	printf("%ld\n", sum);
	return (0);
}
