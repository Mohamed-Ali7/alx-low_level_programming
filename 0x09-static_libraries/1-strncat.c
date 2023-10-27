/**
 * *_strncat - concatenates two strings
 * @dest: the string that will hold the two strings (its value and src value)
 * @src: is the string that will be added to (dest) string
 * @n: it is the numbers of bytes that will be added from string (src) to dest
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int r = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[r] != '\0' && n > r)
	{
		dest[i] = src[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (dest);
}
