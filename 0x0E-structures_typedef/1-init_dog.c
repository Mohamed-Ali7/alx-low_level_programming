#include "dog.h"
#include <stdio.h>
/**
 * init_dog - initializes a variable of type struct dog
 * @d: Is the struct to initialize
 * @name: Is the name of the dog
 * @age: Is the age of the dog
 * @owner: is the owner of the dog
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
