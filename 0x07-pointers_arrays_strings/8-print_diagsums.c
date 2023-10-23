#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square int matrix
 * @a: is the matrix to prnit its diagonals
 * @size: is the size of the matrix
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int r;
	int elements = size * size;
	int diag1 = size + 1;
	int diag2 = size - 1;
	int sum1 = 0;
	int sum2 = 0;

	for (r = 0; r < elements; r++)
	{
		if (r % diag1 == 0)
		{
			sum1 += a[r];
		}
		if (r % diag2 == 0 && r != 0 && r <= (elements - diag2))
		{
			sum2 += a[r];
		}
	}
	printf("%d, %d\n", sum1, sum2);
}
