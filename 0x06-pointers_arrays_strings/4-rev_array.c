/**
 * reverse_array - reverses the content of an array of integers.
 * @a: is the array to reverse
 * @n: is the number of elements of the array
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int i = 0;
	int tmp;

	while (i < n)
	{
		tmp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = tmp;
		i++;
		n--;
	}
}
