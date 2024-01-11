#include "lists.h"
#include <stdio.h>
/**
 * dlistint_len - Counts the number of elements in the linked list
 * @h: Is the pointer to the first node of the linked list
 * Return: The number of elements in the linked list
*/
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t length = 0;

	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	return (length);
}
