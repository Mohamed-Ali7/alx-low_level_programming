#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * shash_table_create - Creates a sorted hash table
 * @size: Is the size of the table
 * Return: A pointer to the newly created hash table
 * or NULL if something went wrong
*/
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *stable = malloc(sizeof(shash_table_t));

	if (stable == NULL)
		return (NULL);

	stable->array = malloc(sizeof(shash_node_t *) * size);
	stable->shead = NULL;
	stable->stail = NULL;

	if (stable->array == NULL)
	{
		free(stable);
		return (NULL);
	}
	stable->size = size;

	for (i = 0; i < size; i++)
		stable->array[i] = NULL;

	return (stable);
}

/**
 * sorted_list - function for insert new node in sorted
 * @ht: pointer to sorted hash table
 * @new_node: pew node to insert
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sbucket = ht->shead;

	if (sbucket == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, sbucket->key) < 0)
		{
			new_node->snext = sbucket;
			new_node->sprev = sbucket->sprev;

			if (!sbucket->sprev)
				ht->shead = new_node;
			else
				sbucket->sprev->snext = new_node;
			sbucket->sprev = new_node;
			return;
		}
		sbucket = sbucket->snext;
	} while (sbucket);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}



/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: IS the hash table to insert into
 * @key: Is the key of the new element (cannot be an empty string)
 * @value: Is the value of the new element
 * Return: 1 if it succeeded, 0 otherwise
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *valuecopy, *keycopy;
	shash_node_t  *bucket, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);
	valuecopy = strdup(value);
	if (!valuecopy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];

	while (bucket)
	{
		if (!strcmp(key, bucket->key))
		{
			free(bucket->value);
			bucket->value = valuecopy;
			return (1);
		}
		bucket = bucket->next;
	}
	new_node = calloc(1, sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(valuecopy);
		return (0);
	}
	keycopy = strdup(key);
	if (!keycopy)
		return (0);
	new_node->key = keycopy;
	new_node->value = valuecopy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	sorted_list(ht, new_node);
	return (1);

}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: Is the hash table to look into
 * @key: Is the key of the element to look for
 * Return: The value associated with the element, or NULL if key not found
*/

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	shash_node_t  *bucket;

	if (!ht || !key || !*key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];
	while (bucket)
	{
		if (!strcmp(key, bucket->key))
			return (bucket->value);
		bucket = bucket->next;
	}
	return (NULL);

}
/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: Is the hash table to print
 * Return: void
*/

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *bucket;
	int not_fin = 0;

	if (!ht)
		return;
	bucket = ht->shead;
	printf("{");
	while (bucket)
	{
		if (not_fin)
			printf(", ");
		printf("'%s': '%s'", bucket->key, bucket->value);
		not_fin = 1;
		bucket = bucket->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: Is the hash table to print
 * Return: void
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *bucket;
	int not_fin = 0;

	if (!ht)
		return;
	bucket = ht->stail;
	printf("{");
	while (bucket)
	{
		if (not_fin)
			printf(", ");
		printf("'%s': '%s'", bucket->key, bucket->value);
		not_fin = 1;
		bucket = bucket->sprev;
	}
	printf("}\n");
}


/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: Is the hash table to delete
 * Return: void
*/

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *cur;
	shash_node_t *next;
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

