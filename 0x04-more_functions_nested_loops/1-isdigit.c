/**
 * _isdigit - Checkes whether a character is digit or not
 * @c: the character to check
 * Return: 1 if the character is digit and 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
