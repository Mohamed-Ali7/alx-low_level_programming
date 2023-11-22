#include <stdio.h>
#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints all the elements of a listint_t list.
 * @head: Is the list to print
 * Return: The size of the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t size = 0;
	const listint_t *tmp = head;
	const listint_t *checker;
	size_t i = 0;

	if  (head == NULL)
	{
		exit(98);
	}
	while (tmp != NULL)
	{
		checker = head;
		i = 0;
		while (i < size)
		{
			if (checker == tmp)
			{
				printf("-> [%p] %d\n", (void *) tmp, tmp->n);
				return (size);
			}
			i++;
			checker = checker->next;
		}
		printf("[%p] %d\n", (void *) tmp, tmp->n);
		tmp = tmp->next;
		size++;
	}
	return (size);
}

