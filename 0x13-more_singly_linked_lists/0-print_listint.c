#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * print_listint - Prints all the elements of a list_t list.
 * @h: Is the list to print
 * Return: The size of the list
 */
size_t print_listint(const listint_t *h)
{
	size_t size = 0;
	const listint_t *tmp = h;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		size++;
	}
	return (size);
}

