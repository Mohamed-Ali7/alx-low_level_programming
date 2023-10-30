#include <stdlib.h>
/**
 * free_grid - frees a 2 dimensional grid from memory
 * @grid: Is the two dimensional array to free from memory
 * @height: Is the height of the two dimensional array
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
