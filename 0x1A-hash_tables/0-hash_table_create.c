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
	unsigned long int i;
	hash_table_t *table = malloc(sizeof(hash_table_t));

	if (table == NULL)
		return (NULL);

	table->array = malloc(sizeof(hash_node_t *) * size);

	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	table->size = size;

	for (i = 0; i < size; i++)
		table->array[i] = NULL;

	return (table);
}
