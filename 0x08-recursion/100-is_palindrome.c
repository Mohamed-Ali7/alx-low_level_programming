#include <stdio.h>

int palindrome(char *str1, char *str2, int len);
int _str_len(char *str);
/**
 * is_palindrome - Checks if a string is a palindrome or not
 * @s: Is the string to check
 * Return: returns 1 if a string is a palindrome and 0 if not.
 */

int is_palindrome(char *s)
{
	int length;

	if (*s == '\0')
	{
		return (1);
	}
	length = _str_len(s);

	return (palindrome(s, s, length - 1));
}


/**
 * _str_len - calculate the length of a string
 * @str: is the string to calculate it length
 * Return: The length of the string str
 */
int _str_len(char *str)
{
	int length = 1;

	if (*str == '\0')
	{
		return (0);
	}
	length += _str_len(str + 1);
	return (length);
}

/**
 * palindrome - Checks if a string is a palindrome or not
 * @str1: Is the string to check
 * @str2: Is the same as str1 to check in reverse order to make a comparison
 * @len: Is the len of the string str1 & str2
 * Return: returns 1 if a string is a palindrome and 0 if not.
 */
int palindrome(char *str1, char *str2, int len)
{
	if (len < 0)
	{
		return (1);
	}

	if (*str1 != str2[len])
	{
		return (0);
	}
	return (palindrome(str1 + 1, str2, len - 1));

}
