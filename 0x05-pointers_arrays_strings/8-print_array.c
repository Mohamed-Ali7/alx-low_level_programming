#include "main.h"
#include <stdio.h>
/**
 * print_array - prints an array of integers, followed by a new line.
 * @a: is the array to print
 * @n: in the length of the array
 * Return: void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("%d", a[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
}
