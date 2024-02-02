#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - Adds an element to the hash table.
 * In case of collision, add the new node at the beginning of the list
 *
 * @ht: IS the hash table to insert into
 * @key: Is the key of the new element (cannot be an empty string)
 * @value: Is the value of the new element
 * Return: 1 if it succeeded, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_element = malloc(sizeof(hash_node_t));
	int index = hash_djb2((const unsigned char *) key) % ht->size;

	if (new_element == NULL)
		return (0);

	new_element->key = strdup(key);
	new_element->value = strdup(value);

	if (ht->array[index] == NULL)
	{
		new_element->next = NULL;
		ht->array[index] = new_element;
	}
	else
	{
		new_element->next = ht->array[index];
		ht->array[index] = new_element;
	}

	return (1);
}
