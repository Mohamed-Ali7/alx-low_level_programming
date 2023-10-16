/**
 * *_strcpy - copies the string (src) to (dest) string
 * @dest: is the char pointer that will hold the copied string
 * @src: is the string to copy
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = '\n';
	return (dest);
}
