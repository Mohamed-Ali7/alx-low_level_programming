#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

bool is_ignored(char c);
/**
 * print_all - Prints anything.
 * @format: is a list of types of arguments passed to the function
 * Return: void
 */

void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	va_list listPtr;
	char *str;

	va_start(listPtr, format);
	while (format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(listPtr, int));
				break;
			case 'i':
				printf("%d", va_arg(listPtr, int));
				break;
			case 'f':
				printf("%f", va_arg(listPtr, double));
				break;
			case 's':
				str = va_arg(listPtr, char *);
				if (str == NULL)
				{
					printf("(nil)");
					break;
				}
				printf("%s", str);
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1] != '\0' && !is_ignored(format[i + 1]))
		{
			printf(", ");
		}
		i++;
	}
	printf("\n");
	va_end(listPtr);
}


bool is_ignored(char c)
{
	return c != 'f' && c != 's' && c != 'e' && c != 'i';
}
