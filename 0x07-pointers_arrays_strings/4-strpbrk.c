#include <stddef.h>

/**
 * *_strpbrk - searches a string for any of a set of bytes.
 * @s: Is the string the will search into.
 * @accept: Is the substring that will locates the first
 * occurrence of any of its  bytes in the string (s)
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0;
	int j = 0;

	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
