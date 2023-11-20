#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * free_listint2 - Frees a list_t list.
 * @head: Is the current first node of the list
 * Return: void
 */

void free_listint2(listint_t **head)
{
	listint_t *prev;

	while (*head != NULL)
	{
		prev = *head;
		*head = (*head)->next;
		free(prev);
	}
	*head = NULL;
}
