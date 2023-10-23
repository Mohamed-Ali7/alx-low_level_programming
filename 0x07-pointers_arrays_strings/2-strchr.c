#include <stddef.h>
/**
 * *_strchr - locates a character in a string.
 * @s: Is the string that will be used to locate char (c)
 * @c: Is the char to locate it first occurrence in the string (s)
 * Return: pointer to the first occurrence char c, or NULL if char not found
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}
	return (NULL);
}
