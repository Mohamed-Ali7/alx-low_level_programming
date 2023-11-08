#include <stddef.h>
/**
 * array_iterator - executes a function given as a
 * parameter on each element of an array.
 * @array: Is the array to iterate
 * @size: Is the size of the array
 * @action: Is the function pointer to execuate
 * Return: void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i = 0;

	if (array != NULL && action != NULL)
	{
		while (size >= 1)
		{
			action(array[i]);
			i++;
			size--;
		}
	}
}
