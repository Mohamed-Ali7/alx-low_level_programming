/**
 * *_strcat - comapre two strings
 * @s1: is the first string to compare
 * @s2: is the second string to compare
 * Return: 0 if s1 = s2, more than 0 if s1 > s2, or less than 0 if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int result = 0;
	int i = 0;

	while(s1[i] != '\0' || s2[i] != '\0')
	{
		result = s1[i] - s2[i];
		if (result != 0)
		{
			break;
		}
		i++;
	}

	return (result);
}
