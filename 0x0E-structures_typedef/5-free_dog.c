#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees struct of type dog from the memory
 * @d: Is the struct to free
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
