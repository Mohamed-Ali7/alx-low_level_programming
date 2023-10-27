/**
 * _strlen - cout length of the received string
 * @s: is the string to return its length
 * Return: the length of the received string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
