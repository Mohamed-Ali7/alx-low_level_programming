#include<stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: Is the size of the hash table
 * Return: A pointer to the newly created hash table
 * or NULL if something went wrong
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table;

	table = calloc(1, sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = calloc(size, sizeof(hash_node_t *));
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	return (table);
}
