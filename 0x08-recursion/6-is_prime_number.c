/**
 * is_prime_number -returns 1 if a number is a prime number otherwise return 0
 * @n: is the number to check
 * Return: 1 if the number (n) is a prime number otherwise return 0
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}
	if (n > 10)
	{
		if (((n % 10) * (n % 10)) == n)
		{
			return (0);
		}
	}
	if (n % 2 != 0 && n != 9)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	is_prime_number(n - 1);
	return (0);
}
