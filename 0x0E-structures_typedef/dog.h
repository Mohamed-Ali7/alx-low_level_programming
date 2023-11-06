#ifndef DOG_STRUCT_H
#define DOG_STRUCT_H

/**
 * struct dog - Is struct that contains informations about a dog
 * @name: the name of the dog
 * @owner: The owner of the dog
 * @age: Age of the dog
 */
typedef struct dog
{
	char *name;
	char *owner;
	float age;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
#endif

#ifndef DOG_H
#define DOG_H

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
