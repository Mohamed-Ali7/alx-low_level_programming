#include <stdlib.h>
#include <stddef.h>

/**
 * *_calloc -  allocates memory for an array, using malloc.
 * @nmemb: Is the number of element of the array
 * @size: Is the byte size of the array's each element
 * Return: A pointer to a newly allocated space in memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	return (ptr);
}
