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
 * set_sorted_list - Inserts the new element in sorted order in a sorted list
 * @ht: A pointer to the hash table
 * @new_element: A pointer to the new element node
 * Return: void
 */
void set_sorted_list(shash_table_t *ht, shash_node_t *new_element)
{
	shash_node_t *stemp;

	if (ht->shead == NULL)
	{
		ht->shead = new_element;
		ht->stail = new_element;
		new_element->snext = NULL;
		new_element->sprev = NULL;
	}
	else
	{
		stemp = ht->shead;
		while (stemp != NULL)
		{
			if (strcmp(new_element->key, stemp->key) < 0)
			{
				new_element->snext = stemp;
				new_element->sprev = stemp->sprev;
				if (stemp->sprev)
					stemp->sprev->snext = new_element;
				stemp->sprev = new_element;
				if (stemp == ht->shead)
					ht->shead = new_element;
				return;
			}
			stemp = stemp->snext;
		}
		new_element->snext = NULL;
		ht->stail->snext = new_element;
		new_element->sprev = ht->stail;
		ht->stail = new_element;
	}
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
	shash_node_t *new_element, *temp;
	int index;

	if (key == NULL || *key == '\0' || ht == NULL)
		return (0);

	index = hash_djb2((const unsigned char *) key) % ht->size;
	temp = ht->array[index];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value), temp->value = strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	new_element = malloc(sizeof(shash_node_t));
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
	set_sorted_list(ht, new_element);
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
	int index;
	shash_node_t *temp;

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
/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: Is the hash table to print
 * Return: void
*/

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *stemp;
	int is_first = 1;

	if (ht == NULL)
		return;
	stemp = ht->shead;
	printf("{");
	while (stemp != NULL)
	{
		if (!is_first)
			printf(", ");
		printf("'%s': '%s'", stemp->key, stemp->value);
		is_first = 0;
		stemp = stemp->snext;
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
	shash_node_t *stemp;
	int is_first = 1;

	if (ht == NULL)
		return;
	stemp = ht->stail;
	printf("{");
	while (stemp != NULL)
	{
		if (!is_first)
			printf(", ");
		printf("'%s': '%s'", stemp->key, stemp->value);
		is_first = 0;
		stemp = stemp->sprev;
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

