#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: Is the hash table to delete
 * Return: void
*/

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *cur;
	hash_node_t *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] == NULL)
			continue;

		cur = ht->array[i];
		next = ht->array[i];
		while (next != NULL)
		{
			cur = next;
			next = next->next;
			free(cur->key);
			free(cur->value);
			free(cur);
		}
	}
	free(ht->array);
	free(ht);
}
