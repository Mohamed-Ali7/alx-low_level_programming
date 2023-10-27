/**
 * *_strncpy - concatenates two strings
 * @dest: the string that will hold the copied string
 * @src: is the string that will be copied to (dest) string
 * @n: it is the numbers of bytes that will be copied from string (src) to dest
 * Return: a pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;
	int r = 0;

	while (n > i)
	{
		dest[i] = src[r];
		i++;
		if (src[r] != '\0')
		{
			r++;
		}
	}
	return (dest);
}
