#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * listint_len - Returns the number of elements in a linked list_t list.
 * @h: Is the list to check its length
 * Return: The size of the list
 */

size_t listint_len(const listint_t *h)
{
	size_t size = 0;
	const listint_t *tmp = h;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
