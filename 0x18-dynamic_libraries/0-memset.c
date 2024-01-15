/**
 * *_memset - fills memory with a constant byte.
 * @s: Is the memory area that will be filled with the constant byte (b)
 * @b: Is the byte which will be used to fill n bytes area pointed to by (s)
 * @n: Is the number of bytes that will be filled in (s)
 * Return: a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
