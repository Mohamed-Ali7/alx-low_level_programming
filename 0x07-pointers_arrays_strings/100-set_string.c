/**
 * set_string - sets the value of a pointer to a char.
 * @s: Is the pointer which will set its value
 * @to: Is the value of that will be assigned to (s) pointer
 * Return: void
 */

void set_string(char **s, char *to)
{
	*s = to;
}
