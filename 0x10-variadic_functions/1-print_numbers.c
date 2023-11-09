#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: Is the seperator char between printed numbers
 * @n: Is the count of numbers that will be printed
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list listPtr;

	va_start(listPtr, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(listPtr, int));

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(listPtr);

}
