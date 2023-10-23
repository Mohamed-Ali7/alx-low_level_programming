/**
 * *_memcpy - fills memory with a constant byte.
 * @dest: the memory area that will be used to store the copied bytes from(src)
 * @src: Is the memory area that will be used to copy from
 * @n: Is the number of bytes that will be copied from (src) to (dest)
 * Return: a pointer to the memory area (dest)
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
