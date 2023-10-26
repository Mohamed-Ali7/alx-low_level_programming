/**
 * wildcmp - Compare two string and checks if they can be considered identical
 * @s1: Is the first string to check
 * @s2: Is the second string to check
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}
	if (*s2 == '*')
	{
		if (*s1 == *(s2 + 1))
		{
			return (wildcmp(s1, s2 + 1));
		}
		else if (*(s2 + 1) == '*')
		{
			return (wildcmp(s1, s2 + 1));
		}
		else if (*(s2 + 1) == 0)
		{
			return (1);
		}
		else if (*s1 == '\0')
		{
			return (0);
		}
		else
		{
			return (wildcmp(s1 + 1, s2));
		}
	}
		if ((*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0'))
		{
			return (0);
		}
		else if (*s1 != *s2)
		{
			return (wildcmp(s1, s2 - 1));
		}
		else
		{
			return (wildcmp(s1 + 1, s2 + 1));
		}
}
