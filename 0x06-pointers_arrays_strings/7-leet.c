/**
 * *leet - encodes a string into 1337.
 * @s: is the string to encode
 * Return: a pointer to the resulting string
 */
char *leet(char *s)
{
	char *encode = "4aA3eE0oO7tT1lL";
	int i = 1;
	int r = 0;

	while (i < 14)
	{
		r = 0;
		while (s[r] != '\0')
		{
			if (s[r] == encode[i] || (s[r]) == encode[i + 1])
			{
				s[r] = encode[i - 1];
			}
			r++;
		}
		i = i + 3;
	}
	return (s);
}
