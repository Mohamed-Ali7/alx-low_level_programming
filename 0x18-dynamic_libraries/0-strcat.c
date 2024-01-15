/**
 * *_strcat - concatenates two strings
 * @dest: the string that will hold the two strings (its value and src value)
 * @src: is the string that will be added to (dest) string
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int r = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[r] != '\0')
	{
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (dest);
}
