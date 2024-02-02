#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: Is the hash table to look into
 * @key: Is the key of the element to look for
 * Return: The value associated with the element, or NULL if key not found
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	int index;
	hash_node_t *temp;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = hash_djb2((const unsigned char *) key) % ht->size;
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
