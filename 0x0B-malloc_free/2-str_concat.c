#include <stddef.h>
#include <string.h>
#include <stdlib.h>
/**
 * *str_concat - concatenates two strings.
 * @s1: Is the first string to concat
 * @s2: Is the second string to concat
 * Return: pointer points to a newly allocated space in memory which contains
 * the contents of s1, followed by the contents of s2, and null terminated
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0;
	int r = 0;
	char *str;
	int s1Len;
	int s2Len;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}
	s1Len = strlen(s1);
	s2Len = strlen(s2);
	str = malloc(sizeof(char) * (s1Len + s2Len + 1));

	if (str == NULL)
	{
		return (NULL);
	}
	while (i < s1Len || r < s2Len)
	{
		if (i < s1Len)
		{
			str[i] = s1[i];
		}
		else
		{
			str[i] = s2[r];
			r++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
