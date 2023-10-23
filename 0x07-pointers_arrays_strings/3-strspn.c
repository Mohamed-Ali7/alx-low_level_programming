/**
 * _strspn - gets the length of a prefix substring.
 * @s: Is the string the will search into.
 * @accept: Is the substring that will search for in (s) string
 * Return: the number of bytes in the initial segment of (s)
 * which consist only of bytes from (accept)
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0;
	int j = 0;
	int number = 0;

	while (s[i] != ' ')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				number++;
			}
			j++;
		}
		i++;
	}
	return (number);
}
