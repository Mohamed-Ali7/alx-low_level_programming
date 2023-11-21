#include "lists.h"
#include <stddef.h>
#include <stdio.h>
/**
 * reverse_listint -  Reverses a listint_t linked list.
 * @head: Is a pointer to the pointer to the first node of the list
 * Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *cur = *head;
	listint_t *prev = NULL;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}

	*head = (*head)->next;
	while (*head != NULL)
	{
		*head = cur->next;
		cur->next = prev;
		prev = cur;
		cur = *head;
	}
	*head = prev;
	return (*head);
}
