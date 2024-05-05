#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - Searches for a value in an array of integers
 * using the Interpolation search algorithm
 *
 * @array: Is a pointer to the first element of the array to search in
 * @size: Is the size of the array
 * @value: Is the value to search for
 * Return: The first index where value is located
*/

int interpolation_search(int *array, size_t size, int value)
{
	int index = -1;
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (!array)
		return (index);

	if (size == 1)
		high--;
	pos = low + (((double)(high - low) / (array[high] - array[low]))
							* (value - array[low]));

	if (pos >= size)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (index);
	}
	while (low <= high)
	{
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
		{
			index = pos;
			break;
		}

		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;

		pos = low + (((double)(high - low) /
			(array[high] - array[low])) * (value - array[low]));
	}
	return (index);
}
