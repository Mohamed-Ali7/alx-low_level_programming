#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: is the string to reverese
 * Return: void
 */
void rev_string(char *s)
{
	int start = 0;
	int end = 0;
	char tmp;

	while (s[end] != '\0')
	{
		end++;
	}
	while (end > start)
	{
		tmp = s[start];
		s[start] = s[end - 1];
		s[end - 1] = tmp;

		end--;
		start++;
	}
}
