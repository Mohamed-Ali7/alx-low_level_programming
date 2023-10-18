#include <stdio.h>
/**
 * *cap_string - capitalizes all words of a string.
 * Separators of words: space, tab, new line, ,, ;, ., !, ?, ", (, ), {, and }
 * @s: is the string to cpatialize
 * Return: a pointer to the resulting string
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		switch (s[i])
		{
			case '\t':
			case ' ':
			case '\n':
			case ',':
			case ';':
			case '.':
			case '!':
			case '?':
			case '"':
			case '(':
			case ')':
			case '{':
			case '}':
				if (s[i] == '\t')
				{
					s[i] = ' ';
				}
				if (s[i + 1] != '\0' && (s[i + 1] >= 97 && s[i + 1] <= 122))
				{
					s[i + 1] -= 32;
				}
		}
		i++;
	}
	return (s);
}
