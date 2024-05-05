#include "search_algos.h"
#include <stdio.h>

/**
 * binary_search - Searches for a value in an array of integers
 * using the Binary search algorithm
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The index where value is located
*/

int binary_search(int *array, size_t size, int value)
{
	int index = -1;
	size_t start = 0, tmp_start;
	size_t end = size - 1;
	size_t middle = start + (end - start) / 2;

	if (!array)
		return (index);

	while (end >= start)
	{
		tmp_start = start;
		printf("Searching in array: ");

		while (tmp_start <= end)
		{
			printf("%d", array[tmp_start]);
			if (tmp_start != end)
				printf(", ");
			else
				printf("\n");
			tmp_start++;
		}
		if (array[middle] == value)
		{
			index = middle;
			break;
		}

		if (array[middle] > value)
			end = middle - 1;
		else
			start = middle + 1;

		middle = start + (end - start) / 2;
	}

	return (index);
}
