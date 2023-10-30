#include <stddef.h>
#include <stdlib.h>
#include <string.h>
/**
 * *_strdup - Write a function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter.
 * @str: Is the string to copy
 * Return: The created array
 */
char *_strdup(char *str)
{
	char *copiedStr;
	int len = strlen(str);

	copiedStr = malloc(sizeof(char) * (len + 1));

	if (str == NULL || copiedStr == NULL)
	{
		return (NULL);
	}

	while (len >= 1)
	{
		copiedStr[len - 1] = str[len - 1];
		len--;
	}
	return (copiedStr);
}
