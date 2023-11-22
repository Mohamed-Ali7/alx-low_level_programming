#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Is a pointer to the pointer to the first node of the list
 * Return: The size of freed linked list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *tmp = *h;
	listint_t *prev;
	int checker;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}
	while (tmp != NULL)
	{
		checker = tmp - tmp->next;
		if (checker > 0)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev);
			size++;
		}
		else
		{
			free(tmp);
			*h = NULL;
			size++;
			break;
		}
	}

	*h = NULL;
	return (size);
}
