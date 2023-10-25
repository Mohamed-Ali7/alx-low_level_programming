int _sqrt(int start, int end, int num);

/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: Is the number to get its natural square root
 * Return: The natural square root of (n).
 */

int _sqrt_recursion(int n)
{
	return (_sqrt(1, n, n));
}

/**
 * _sqrt - a helper function to get the natural square root of a number.
 * @start: Is the start point to calculate the middle of the number
 * @end: Is the end point to calculate middle of the number
 * @num: Is the number to calculate its square root
 * Return: The natural square root of (num).
 */

int _sqrt(int start, int end, int num)
{
	int mid = (end + start) / 2;

	if (start > end)
	{
		return (-1);
	}

	if (mid * mid == num)
	{
		return (mid);
	}
	else if (mid * mid < num)
	{
		return (_sqrt(mid + 1, end, num));
	}
	else
	{
		return (_sqrt(start, mid - 1, num));
	}
}
