#include <stdio.h>
/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: Is the number to get its natural square root
 * Return: The natural square root of (n).
 */

int _sqrt_recursion(int n)
{
	int root = 1;

	if (n < 0) 
	{
		return (-1);
	}
	
	if (n == 0 || n == 1)
	{
		return n;
	}

	root += _sqrt_recursion(n - 1);
	printf("N = %d     ROOT = %d\n", n, root);
	return root;
}
