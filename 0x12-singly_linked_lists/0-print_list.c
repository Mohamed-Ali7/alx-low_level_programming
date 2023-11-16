#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: Is the list to print
 * Return: The size of the list
 */
size_t print_list(const list_t *h)
{
	size_t size = 0;
	const list_t *tmp = h;

	while (tmp != NULL)
	{
		if (tmp->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", tmp->len, tmp->str);
		}
		tmp = tmp->next;
		size++;
	}
	return (size);
}
