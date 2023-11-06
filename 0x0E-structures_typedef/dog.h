#ifndef DOG_STRUCT_H
#define DOG_STRUCT_H

/**
 * struct dog - Is struct that contains informations about a dog
 * @name: the name of the dog
 * @owner: The owner of the dog
 * @age: Age of the dog
 */
struct dog
{
	char *name;
	char *owner;
	float age;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
#endif
