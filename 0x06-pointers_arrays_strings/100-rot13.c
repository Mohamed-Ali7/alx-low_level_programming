#include <stdio.h>
/**
 * *rot13 - encodes a string into rot13.
 * @s: is the string to encode
 * Return: a pointer to the resulting string
 */
char *rot13(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		while ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
		{
			if ((s[i] < 'Z' && (s[i] + 13) > 'Z') || (s[i] >= 'a' && (s[i] + 13) > 'z'))
			{
				s[i] -= 26;
			}
			s[i] = s[i] + 13;
			i++;
		}

		i++;
	}
	return (s);
}
