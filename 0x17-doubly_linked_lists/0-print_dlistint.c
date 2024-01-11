#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint - Prints all the elements of a doubly linked list.
 * @h: Is the pointer to the first node of the linked list
 * Return: The number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp = h;
	size_t length = 0;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		length++;
	}
	return (length);
}
