/**
 * swap_int - swaps the values of two integers.
 * @a: a pointer to the first integer to swap
 * @b: a pointer to the second integer to swap
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}
