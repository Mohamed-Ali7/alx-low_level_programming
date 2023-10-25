/**
 * factorial - returns the factorial of a given number.
 * @n: Is the number to return its factorial
 * Return: the factorial of (n)
 */

int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}

	if (n == 0 || n == 1)
	{
		return 1;
	}

	return n * factorial(n - 1);
}
