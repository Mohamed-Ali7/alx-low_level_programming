#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table.
 * @ht: Is the hash table to print
 * Return: void
*/
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int i;
	int is_first = 1;

	if (ht == NULL)
		return;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] == NULL)
			continue;

		temp = ht->array[i];
		while (temp != NULL)
		{
			if (!is_first)
				printf(", ");
			is_first = 0;
			printf("\'%s\': \'%s\'", temp->key, temp->value);
			temp = temp->next;
		}
	}
	printf("}\n");
}
