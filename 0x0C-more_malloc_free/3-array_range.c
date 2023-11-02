#include <stdlib.h>
#include <stdio.h>

/**
 * *array_range - creates an array of integers.
 * @min: Is the number that the array will start with
 * @max: Is the number that the array will end with
 * Return: A pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int arrLen = (max - min) + 1;
	int *arr;
	int i = 0;

	if (min > max)
	{
		return (NULL);
	}
	arr = malloc(sizeof(int *) * arrLen);

	if (arr == NULL)
	{
		return (NULL);
	}

	while (min <= max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
