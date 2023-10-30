#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
/**
 * *argstostr - concatenates all the arguments of the program.
 * @ac: Is the number of the arguments
 * @av: Is the program arguments which is array of strings
 * Return: Returns a pointer to a new string, or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	char *args;
	int len = 0;
	int i;
	int r;
	int x = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		r = 0;
		while (av[i][r] != '\0')
		{
			len++;
			r++;
		}
		len++;
	}

	args = malloc(sizeof(char) * len + 1);

	for (i = 0; i < ac; i++)
	{
		r = 0;
		while (av[i][r] != '\0')
		{
			args[x] = av[i][r];
			x++;
			r++;
		}
		args[x] = '\n';
		x++;
	}
	return (args);
}
