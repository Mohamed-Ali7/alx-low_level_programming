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
	listint_t *cur = *head;

	if (head == NULL || *head == NULL)
	{
		return;
	}
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	*head = NULL;
	head = NULL;
}
