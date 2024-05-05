#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * search_block - Searches for a value in a part of an array of integers
 * @array: Is a pointer to the first element of the array to search in
 * @start: Is the index to start searching from
 * @end: Is the index to stop searching at
 * @size: Is the size of the entire array
 * @value: Is the value to search for
 * Return: The first index where value is located
 */

int search_block(int *array, size_t start, size_t end, size_t size, int value)
{
	int index = -1;

	printf("Value found between indexes [%ld] and [%ld]\n", start, end);

	if (end >= size)
		end = size - 1;
	for (; start <= end; start++)
	{
		printf("Value checked array[%ld] = [%d]\n", start, array[start]);
		if (array[start] == value)
		{
			index = start;
			break;
		}
	}
	return (index);
}

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
			{
				index = search_block(array, block_start, block_end, size, value);
				break;
			}
		}
		else
		{
			index = search_block(array, block_start, block_end, size, value);
			break;
		}
		block_end += jump_step;
	}
	return (index);
}
