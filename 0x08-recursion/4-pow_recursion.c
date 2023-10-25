/**
 * _pow_recursion - returns the value of x raised to the power of y.
 * @x: Is the number to calculate its power to y
 * @y: Is the power number that number (x) will raised to
 * Return: returns the value of x raised to the power of y.
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	if (y == 0)
	{
		return (1);
	}

	x *= _pow_recursion(x, y - 1);

	return (x);
}
