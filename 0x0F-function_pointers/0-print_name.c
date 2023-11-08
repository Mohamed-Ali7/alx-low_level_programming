/**
 * print_name - prints a name using function pointers
 * @name: Is the name to print
 * @f: Is the function pointer to use
 * Return: void
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL)
	{
		f(name);
	}
}
