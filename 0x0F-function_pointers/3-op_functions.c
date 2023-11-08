#include <stdio.h>
#include <stdlib.h>
/**
 * op_add - Adds two integers
 * @a: is the first interger to add
 * @b: Is the seconde integer to add
 * Return: The sum of two integers
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - Subtratc two integers
 * @a: is the first interger to subtract
 * @b: Is the seconde integer to subtract
 * Return: The difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - Multiply two integers
 * @a: is the first interger to multiply
 * @b: Is the seconde integer to multiply
 * Return: The product of multipling a and b
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - Divides two integers
 * @a: is the first interger to divide
 * @b: Is the seconde integer to divide
 * Return: The product of dividing a by b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - Divides two integers
 * @a: Is the number to calcualte its division by b reminder
 * @b: Is the number that a will be divided by
 * Return: The remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
