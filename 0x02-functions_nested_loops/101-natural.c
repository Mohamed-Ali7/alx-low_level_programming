#include <stdio.h>

/**
 * main - The entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int checker = 1;
	int sum = 0;
	while (checker < 1024)
	{
		if ((checker % 5) == 0 || (checker % 3) == 0)
		{
			sum += checker;
		}
		checker++;
	}
	printf("%d\n", sum);
	return (0);
}

