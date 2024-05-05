#include "search_algos.h"
#include <stdio.h>

/**
 * exponential_search - Searches for a value in an array of integers
 * using the Exponential search algorithm
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The first index where value is located
*/

int exponential_search(int *array, size_t size, int value)
{
	int index = -1;
	size_t i = 1, start = 0, tmp_start, end, middle;

	if (!array)
		return (index);
	if (array[0] == value)
		return (0);
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]), i *= 2;
	}
	start = i / 2;
	end = i < size ? i : size - 1;
	middle = start + (end - start) / 2;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, end);
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
