#include "main.h"

/**
 * print_last_digit -  prints the last digit of an
 * @n: is the number to return its last digit
 *
 * Return: the last digit of the recieved number
 */
int print_last_digit(int n)
{
	int lstDigit = n % 10;

	if (lstDigit < 0)
	{
	lstDigit *= -1;
	}
	_putchar('0' + lstDigit);
	return (lstDigit);
}
