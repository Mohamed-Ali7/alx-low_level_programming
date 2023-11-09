#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: Is the seperator char between the printed strings
 * @n: Is the count of strings that will be printed
 * Return: void
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list listPtr;
	char *str;

	va_start(listPtr, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(listPtr, char *);
		if (str != NULL)
		{
			printf("%s", str);
		}
		else
		{
			printf("(nil)");
		}

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");
	va_end(listPtr);

}
