#include "dog.h"
#include <stdlib.h>
#include <stdio.h>

int _length(char *s);
/**
 * new_dog - Creates a new dog.
 * @name: Is the name of the new dog
 * @age: Is the age of the new dog
 * @owner: Is the owner of the new dog
 * Return: new dog struct
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *newDog;
	int nameLen = _length(name);
	int ownerLen = _length(owner);
	int i;

	newDog = malloc(sizeof(dog_t));
	if (newDog == NULL)
	{
		return (NULL);
	}

	newDog->name = malloc(nameLen + 1);
	if (newDog->name == NULL)
	{
		free(newDog);
		return (NULL);
	}
	newDog->owner = malloc(ownerLen + 1);
	if (newDog->owner == NULL)
	{
		free(newDog);
		free(newDog->name);
		return (NULL);
	}
	for (i = 0; i < nameLen; i++)
	{
		newDog->name[i] = name[i];
	}
	newDog->name[i] = '\0';

	for (i = 0; i < ownerLen; i++)
	{
		newDog->owner[i] = owner[i];
	}
	newDog->owner[i] = '\0';

	newDog->age = age;
	return (newDog);
}

/**
 * _length - Calculate the length of a string
 * @s: is the string to calcualte its length
 * Return: the length of the string (s)
 */
int _length(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
