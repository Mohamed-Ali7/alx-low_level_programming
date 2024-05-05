#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in an array of integers
 * using the Jump search algorithm
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The first index where value is located
*/

int jump_search(int *array, size_t size, int value)
{
	int index = -1;
	int found = 0;
	size_t jump_step = sqrt(size);
	size_t block_start = 0;
	size_t block_end = jump_step;

	if (!array)
		return (index);
	for (block_start = 0; block_start < size; block_start += jump_step)
	{
		printf("Value checked array[%ld] = [%d]\n", block_start, array[block_start]);
		if (block_end < size)
		{
			if (array[block_end] >= value)
				found = 1;
		}
		if (block_end > size || found)
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				block_start, block_end);
			if (!found)
				block_end = size - 1;
			for (; block_start <= block_end; block_start++)
			{
				printf("Value checked array[%ld] = [%d]\n",
								block_start, array[block_start]);
				if (array[block_start] == value)
				{
					index = block_start;
					block_start = size;
					break;
				}
			}
		}
		block_end += jump_step;
	}
	return (index);
}
