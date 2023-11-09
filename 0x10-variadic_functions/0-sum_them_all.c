#include <stdarg.h>

/**
 * sum_them_all - Sums all the passed numbers
 * @n: Is the number of passed parameters
 * Return: The sum of the passed numbers
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	int sum = 0;
	va_list listPtr;

	va_start(listPtr, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(listPtr, int);
	}

	va_end(listPtr);
	return (sum);
}
