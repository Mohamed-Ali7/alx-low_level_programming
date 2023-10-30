#include <stdlib.h>
#include <stddef.h>
/**
 * **alloc_grid - returns a pointer to a 2 dimensional array of integers.
 * @width: Is the width of the two dimensional array
 * @height: Is the height of the two dimensional array
 * Return: a pointer to the 2 dimensional array of integers.
 */
int **alloc_grid(int width, int height)
{
	int **arr;
	int i;
	int r;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	arr = malloc(sizeof(int) * height);

	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(sizeof(int) * width);
	}

	for (i = 0; i < height; i++)
	{
		for (r = 0; r < width; r++)
		{
			arr[i][r] = 0;
		}
	}
	return (arr);
}
