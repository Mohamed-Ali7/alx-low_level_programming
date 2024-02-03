#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * set_spair - mallocs a key/value pair to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 *
 * Return: pointer to the new node.
 */
shash_node_t *set_spair(const char *key, const char *value)
{
	shash_node_t *node = malloc(sizeof(shash_node_t));

	if (node == NULL)
		return (NULL);
	node->key = malloc(strlen(key) + 1);
	if (node->key == NULL)
		return (NULL);
	node->value = malloc(strlen(value) + 1);
	if (node->value == NULL)
		return (NULL);
	strcpy(node->key, key);
	strcpy(node->value, value);
	return (node);
}

/**
 * set_spair_only - (no collision) set key:value pair to first array element
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 * @index: the key's index.
 *
 * Return: the node, or NULL if failed.
 */
shash_node_t *set_spair_only(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *node = set_spair(key, value);

	if (node == NULL)
		return (NULL);
	node->next = NULL;
	ht->array[index] = node;
	return (node);
}

/**
 * update_value - updates the value of a given node.
 * @node: pointer to the node.
 * @value: string to put at the node.
 *
 * Return: 1 on success, 0 on fail.
 */
int update_value(shash_node_t *node, const char *value)
{
	if (strcmp(node->value, value) == 0)
		return (1);
	free(node->value);
	node->value = malloc(strlen(value) + 1);
	if (node->value == NULL)
		return (0);
	strcpy(node->value, value);
	return (1);
}

/**
 * set_spair_front - sets key:value pair node to front of given index's list.
 * @ht: pointer to the sorted hash table.
 * @key: the key, a string that cannot be empty.
 * @value: the value associated with the key, can be an empty string.
 * @index: the key's index.
 *
 * Return: the new node, or NULL if failed.
 */
shash_node_t *set_spair_front(shash_table_t *ht, const char *key,
			     const char *value, unsigned long int index)
{
	shash_node_t *node = set_spair(key, value);

	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	return (node);
}

/**
 * slist_set_first - sets the first addition to the sorted list.
 * @ht: pointer to the sorted hash table.
 * @node: pointer to the first node on the table.
 *
 * Return: Always 1.
 */
int slist_set_first(shash_table_t *ht, shash_node_t *node)
{
	node->sprev = NULL;
	node->snext = NULL;
	ht->shead = node;
	ht->stail = node;
	return (1);
}

/**
 * slist_set - sets a new node before the given old node.
 * @ht: pointer to the sorted hash table.
 * @old_node: the node to place the new node in front of.
 * @node: the new node to place in front of the old one.
 *
 * Return: Always 1 (success).
 */
int slist_set(shash_table_t *ht, shash_node_t *old_node, shash_node_t *node)
{
	if (old_node->sprev == NULL)
		ht->shead = node;
	node->snext = old_node;
	node->sprev = old_node->sprev;
	old_node->sprev = node;
	if (node->sprev != NULL)
		node->sprev->snext = node;
	return (1);
}

/**
 * slist_set_end - sets a node at the end of the sorted list
 * @ht: pointer to the sorted hash table.
 * @node: the node to place at the end.
 *
 * Return: Always 1 (success).
 */
int slist_set_end(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *old_node = ht->stail;

	ht->stail = node;
	node->snext = NULL;
	node->sprev = old_node;
	old_node->snext = node;
	return (1);
}


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
	unsigned long int index;
	shash_node_t *node, *curr_old_node;

	if (key == NULL || ht == NULL)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];
	if (node == NULL)
		node = set_spair_only(ht, key, value, index);
	else
	{
		while (node != NULL)
		{
			if (strcmp(node->key, key) == 0)
				return (update_value(node, value));
			node = node->next;
		}
		node = set_spair_front(ht, key, value, index);
	}
	if (node == NULL)
		return (0);
	if (ht->shead == NULL)
		return (slist_set_first(ht, node));
	curr_old_node = ht->shead;
	while (curr_old_node != NULL)
	{
		if (strcmp(curr_old_node->key, node->key) >= 0)
			return (slist_set(ht, curr_old_node, node));
		curr_old_node = curr_old_node->snext;
	}
	return (slist_set_end(ht, node));
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

