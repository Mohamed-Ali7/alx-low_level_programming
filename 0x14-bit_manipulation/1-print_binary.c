#include <stdio.h>
#include "main.h"

void _print_binary_recur(unsigned long int n);
/**
 * print_binary - Prints the binary representation of a number.
 * @n: Is the number to print its binary format
 * Return: void
 */
void print_binary(unsigned long int n)
{

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	_print_binary_recur(n);
}
/**
 * _print_binary_recur - Prints the binary format of a number recursively.
 * @n: Is the number to print its binary format
 * Return: void
 */
void _print_binary_recur(unsigned long int n)
{
	if (n == 0)
	{
		return;
	}
	_print_binary_recur(n >> 1);
	if (n & 1)
	{
		_putchar('1');
	}
	else
	{
		_putchar('0');
	}
}
