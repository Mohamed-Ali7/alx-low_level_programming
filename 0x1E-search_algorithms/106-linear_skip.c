#include <stdio.h>
#include "search_algos.h"


/**
 * get_element_by_index - Searches for a node in a list using its index
 * @list: Is a pointer to the head of the list to search in
 * @index: Is the index to find its node
 * Return: The node at the passed index
*/

skiplist_t *get_element_by_index(skiplist_t *list, size_t index)
{
	skiplist_t *result = NULL;

	if (!list)
		return (result);

	while (list)
	{
		if (list->index == index)
		{
			result = list;
			break;
		}
		list = list->next;
	}
	return (result);
}

/**
 * search_block - Searches for a value in a part of a list of integers
 * @list: Is a pointer to the head of the list to search in
 * @end: Is the index to stop searching at
 * @value: Is the value to search for
 * Return: The first index where value is located
 */

skiplist_t *search_block(skiplist_t *list, size_t end, int value)
{
	skiplist_t *result = NULL;

	printf("Value found between indexes [%ld] and [%ld]\n", list->index, end);
	while (list)
	{
		printf("Value checked at index [%ld] = [%d]\n",
						list->index, list->n);

		if (list->n == value)
		{
			result = list;
			break;
		}
		list = list->next;
	}
	return (result);
}

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Is a pointer to the head of the skip list to search in
 * @value: Is the value to search for
 * Return: A pointer on the first node where value is located
*/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *result = NULL, *express, *cur = list, *lsit_last_node;

	if (!list)
		return (result);

	express = cur->express;
	while (express)
	{
		express = cur->express;
		printf("Value checked at index [%ld] = [%d]\n", express->index, express->n);
		if (express->n >= value)
		{
			result = search_block(cur, express->index, value);
			break;
		}
		cur = express;
		express = express->express;
	}
	if (!result)
	{
		lsit_last_node = cur;
		while (lsit_last_node->next)
			lsit_last_node = lsit_last_node->next;
		result = search_block(cur, lsit_last_node->index, value);
	}
	return (result);
}
