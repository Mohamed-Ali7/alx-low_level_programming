/**
 * wildcmp_helper - Checks if two strings can be considered identical
 * @str1: Is the first string to check
 * @str2: Is the second string to check
 * @location: Is the memore address of string (str2)
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp_helper(char *str1, char *str2, char *location)
{
	if (*str2 == '*')
	{
		if (*str1 == *(str2 + 1))
		{
			return (wildcmp_helper(str1, str2 + 1, location));
		}
		else if (*(str2 + 1) == '*')
		{
			return (wildcmp_helper(str1, str2 + 1, location));
		}
		else if (*(str2 + 1) == '\0')
		{
			return (1);
		}
		else if (*str1 == '\0')
		{
			return (0);
		}
		else
		{
			return (wildcmp_helper(str1 + 1, str2, location));
		}
	}
	if (*str1 == '\0' && *str2 == '\0')
	{
		return (1);
	}
	else if (*str1 == '\0' || location > str2)
	{
		return (0);
	}
	else if (*str1 != *str2)
	{
		return (wildcmp_helper(str1, str2 - 1, location));
	}
	else
	{
		return (wildcmp_helper(str1 + 1, str2 + 1, location));
	}
}

/**
 * wildcmp - Compare two string and checks if they can be considered identical
 * @s1: Is the first string to check
 * @s2: Is the second string to check
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */

int wildcmp(char *s1, char *s2)
{
	return (wildcmp_helper(s1, s2, s2));
}
