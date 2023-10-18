/**
 * *string_toupper - changes all lowercase letters of a string to uppercase.
 * @s: is the string to change its lowercase letters to upper
 * Return: a pointer to the resulting string
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 97 && s[i] <= 122)
		{
			s[i] -= 32;
		}
		i++;
	}
	return (s);
}
