#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * get_element_by_index - Searches for a node in a list using its index
 * @list: Is a pointer to the head of the list to search in
 * @index: Is the index to find its node
 * Return: The node at the passed index
*/

listint_t *get_element_by_index(listint_t *list, size_t index)
{
	listint_t *result = NULL;

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

listint_t *search_block(listint_t *list, size_t end, int value)
{
	listint_t *result = NULL;

	printf("Value found between indexes [%ld] and [%ld]\n", list->index, end);
	while (list)
	{
		printf("Value checked at index [%ld] = [%d]\n", list->index, list->n);

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
 * jump_list - Searches for a value in a sorted list of integers
 * using the Jump search algorithm.
 *
 * @list: Is a pointer to the head of the list to search in
 * @size: Is the number of nodes in list
 * @value: Is the value to search for
 * Return: A pointer to the first node where value is located
*/

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *result = NULL, *prev, *cur = list;
	size_t jump_step = sqrt(size), block_start = 0, block_end = jump_step;
	size_t block_last_index = 0;

	if (!list)
		return (result);

	for (block_start = 0; block_start < size; block_start += jump_step)
	{
		block_last_index = block_end < size ? block_end : size - 1;
		prev = cur;
		cur = get_element_by_index(prev, block_last_index);
		printf("Value checked at index [%ld] = [%d]\n", cur->index, cur->n);
		if (block_end < size)
		{
			if (cur->n >= value)
			{
				result = search_block(prev, block_last_index, value);
				break;
			}
		}
		else
		{
			result = search_block(prev, block_last_index, value);
			break;
		}
		block_end += jump_step;
	}

	return (result);
}
