#include <stddef.h>

/**
 * int_index - searches for an integer.
 * @array: Is the array where the integer is searched
 * @size: Is the size of the array
 * @cmp: Is the function pointer to execuate
 * Return: Index of first element for which the cmp function doesn't return 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && cmp != NULL && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
			{
				return (i);
			}
		}
	}
	return (-1);
}
