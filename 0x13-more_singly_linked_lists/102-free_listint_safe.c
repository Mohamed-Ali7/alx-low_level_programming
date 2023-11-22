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
	listint_t *prev;
	listint_t *checker;
	listint_t *tmp = *h;
	size_t i = 0;
	size_t size = 0;

	if (h == NULL || *h == NULL)
	{
		return (0);
	}
	while (tmp != NULL)
	{
		checker = *h;
		i = 0;
		while (i < size)
		{
			if (checker == tmp)
			{
				*h = NULL;
				return (size);
			}
			i++;
			if (checker != NULL)
			{
				checker = checker->next;
			}
		}
		prev = tmp;
		tmp = tmp->next;
		free(prev);
		size++;
	}
	*h = NULL;

	return (size);
}
