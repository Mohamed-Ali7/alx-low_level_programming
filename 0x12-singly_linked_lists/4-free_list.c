#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_list - Frees a list_t list.
 * @head: Is the current first node of the list
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *prev;

	while (head != NULL)
	{
		prev = head;
		head = head->next;
		free(prev->str);
		free(prev);
	}
}
