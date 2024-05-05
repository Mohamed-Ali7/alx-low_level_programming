#include "search_algos.h"
#include <stdio.h>

/**
 * binary_recursive - Searches for a value in an array of integers
 * using the Binary search algorithm recursively
 *
 * @array: Is a pointer to the first element of the array to search in
 * @start: Is the first index of the array
 * @end: Is the last index of the array
 * @value: Is the value to search for
 * Return: The first index where value is located
 */

int binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t i = 0;
	size_t middle;

	if (start > end)
		return (-1);

	middle = start + (end - start) / 2;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i != end)
			printf(", ");
		else
			printf("\n");
	}

	if (array[middle] == value)
	{
		if (middle == start || array[middle - 1] != value)
			return (middle);
		else
			return (binary_recursive(array, start, middle, value));
	}
	else if (array[middle] > value)
		return (binary_recursive(array, start, middle, value));
	else
		return (binary_recursive(array, middle + 1, end, value));
}

/**
 * advanced_binary - Searches for a value in an array of integers
 * using the Binary search algorithm recursively
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The index where value is located
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}
