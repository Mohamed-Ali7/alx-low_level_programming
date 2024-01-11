#include "lists.h"
#include <stdio.h>
/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Is the pointer to the first node of the linked list
 * Return: void
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next = head;

	while (next != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
