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
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: IS the hash table to insert into
 * @key: Is the key of the new element (cannot be an empty string)
 * @value: Is the value of the new element
 * Return: 1 if it succeeded, 0 otherwise
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = hash_djb2((const unsigned char *) key) % ht->size;
	shash_node_t *current;
	shash_node_t *node = ht->array[index];
	shash_node_t *new_node;

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
		node = node->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for new node\n");
		return (0);
	}

	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[index];
	new_node->sprev = NULL;
	new_node->snext = NULL;

	ht->array[index] = new_node;
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		current = ht->shead;
		while (current != NULL && strcmp(current->key, key) < 0)
		{
			current = current->snext;
		}
		if (current == NULL)
		{
			new_node->sprev = ht->stail;
			ht->stail->snext = new_node;
			ht->stail = new_node;
		}
		else
		{
			new_node->sprev = current->sprev;
			new_node->snext = current;
			if (current->sprev != NULL)
			{
				current->sprev->snext = new_node;
			}
			else
			{
				ht->shead = new_node;
			}
			current->sprev = new_node;
		}
	}
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
	unsigned long int index;
	shash_node_t *node;

	if (ht == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
		return (NULL);
	if (strcmp(ht->array[index]->key, key) == 0)
		return (ht->array[index]->value);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
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
	unsigned long int count = 0;
	shash_node_t *node = ht->shead;

	if (ht == NULL)
		return;
	printf("{");
	while (node != NULL)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		count++;
	}
	printf("}\n");
}

/**
 * shash_table_print - Prints a sorted hash table in reverse order.
 * @ht: Is the hash table to print
 * Return: void
*/
void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int count = 0;
	shash_node_t *node = ht->stail;

	if (ht == NULL)
		return;
	printf("{");
	while (node != NULL)
	{
		if (count > 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		count++;
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

