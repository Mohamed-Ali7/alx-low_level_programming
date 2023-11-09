#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>

int is_valid(char c);
/**
 * print_all - Prints anything.
 * @format: is a list of types of arguments passed to the function
 * Return: void
 */

void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	int checker = 0;
	va_list listPtr;
	char *str;

	va_start(listPtr, format);
	while (format != NULL && format[i] != '\0')
	{
		if (is_valid(format[i]) && checker != 0)
		{
			printf(", ");
		}
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(listPtr, int));
				checker++;
				break;
			case 'i':
				printf("%d", va_arg(listPtr, int));
				checker++;
				break;
			case 'f':
				printf("%f", va_arg(listPtr, double));
				checker++;
				break;
			case 's':
				str = va_arg(listPtr, char *);
				if (str == NULL)
				{
					str = "(nil)";
				}
				printf("%s", str);
				checker++;
				break;
		}
		i++;
	}
	printf("\n");
	va_end(listPtr);
}
/**
 * is_valid - Checks if the character is a valid format
 * @c: is the character to check
 * Return: True if it is valid or false if it is not
 */
int is_valid(char c)
{
	return (c == 'c' || c == 'i' || c == 'f' || c == 's');
}
