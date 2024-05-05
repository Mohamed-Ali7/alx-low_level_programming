#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - Searches for a value in an array of integers
 * using the Linear search algorithm
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The first index where value is located
*/

int linear_search(int *array, size_t size, int value)
{
	int index = -1;
	size_t i;

	if (!array)
		return (index);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			index = i;
			break;
		}
	}

	return (index);
}
