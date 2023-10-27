/**
 * _isupper - Checkes whether a character is uppercase or not
 * @c: the character to check
 * Return: 1 if the character is upper and 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
