#include "hash_tables.h"

/**
 * key_index - Finds the index of a key using djb2 function.
 * @key: Is the key to return it's index
 * @size: Is the size of the hash table
 * Return: Return the index of the key.
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key) % size;

	return (index);
}
