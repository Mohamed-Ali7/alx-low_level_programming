#include <stddef.h>
#include <stdlib.h>

/**
 * *create_array - creates an array of chars,
 * and initializes it with a specific char.
 * @size: Is the size of the array
 * @c: Is the char that the array will be initialized with
 * Return: The created array
 */
char *create_array(unsigned int size, char c)
{
	char *arr = malloc(sizeof(char) * size);

	if (size == 0)
	{
		return (NULL);
	}

	while (size >= 1)
	{
		arr[size - 1] = c;
		size--;
	}
	return (arr);
}
