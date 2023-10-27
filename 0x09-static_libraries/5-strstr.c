#include <stddef.h>

/**
 * *_strstr - locates a substring
 * @haystack: Is the string which will search into.
 * @needle: substring that will locates its first occurrence in the string (s)
 * Return: a pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j = 0;
	int r = 0;

	while (haystack[i] != '\0')
	{
		r = i;
		j = 0;

		while (needle[j] == haystack[r] && needle[j] != '\0')
		{
			j++;
			r++;
		}
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}
		i++;
	}
	return (NULL);
}
