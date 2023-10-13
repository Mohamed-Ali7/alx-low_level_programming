#include <stdio.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	long num = 612852475143;
	int counter = 2;
	int sqrtNum = sqrt(num);
	int largest = 0;

	while (counter <= sqrtNum)
	{
		while ((num % counter) == 0)
		{
			largest = counter;
			num = num / counter;
		}
		counter++;
	}
	if (num > 2)
	{
		largest = num;
	}
	printf("%d\n", largest);
	return (0);
}
