#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/**
 * *_calloc -  allocates memory for an array, using malloc.
 * @nmemb: Is the number of element of the array
 * @size: Is the byte size of the array's each element
 * Return: A pointer to a newly allocated space in memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	char *tmp;
	unsigned int length = nmemb * size;

	if (length == 0)
	{
		return (NULL);
	}

	ptr = malloc(length);
	tmp = (char *) ptr;

	if (ptr == NULL)
	{
		return (NULL);
	}
	while (length >= 1)
	{
		tmp[length - 1] = 0;
		length--;
	}
	return (ptr);
}
