#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Is the pointer to the pointer of the first node of the linked list
 * @idx: Is the index where the new node will be inserted
 * @n: Is the data value of the new node
 * Return: The address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *cur = *head;
	listint_t *prev = *head;
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}
	while (cur != NULL && i < idx)
	{
		prev = cur;
		cur = cur->next;
		i++;
	}

	if (i != idx)
	{
		return (NULL);

	}
	new_node = malloc(sizeof(listint_t));
	new_node->n = n;
        new_node->next = cur;
	prev->next = new_node;
	printf("Cur is : %d and new node: %d and IDX: %d\n", cur->n, new_node->n, idx);
	return (*head);
}
