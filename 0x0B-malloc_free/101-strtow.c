#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initArr(char *str, char **strArr, int arrSize);
/**
 * **strtow - splits a string into words.
 * @str: Is the string to split
 * Return: A pointer to an array of strings (words)
 */

char **strtow(char *str)
{
	char **strArr;
	int arrSize = 1;
	int i, x;
	int strLen = 0;
	int r = 0;
	char cur;
	char next;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		cur = str[i];
		next = str[i + 1];
		if ((cur <= 32 || cur >= 127) && (!(next > 32) || !(next < 127)))
		{
			continue;
		}
		else if ((str[0] <= 32 || str[0] >= 127) && r == 0)
		{
			r++;
			continue;
		}
		if (str[i] == ' ')
		{
			arrSize++;
		}
	}
	if (arrSize == 1)
	{
		return (NULL);
	}
	strArr = malloc(sizeof(char *) * (arrSize + 1));
	if (strArr == NULL)
	{
		return (NULL);
	}
	r = 0;
	i = 0;
	for (x = 0; x < arrSize; x++)
	{
		strLen = 0;
		while (str[i] != '\0')
		{
			cur = str[i];
			next = str[i + 1];
			if ((cur <= 32 || cur >= 127) && (!(next > 32) || !(next < 127)))
			{
				i++;
				continue;
			}
			else if ((str[0] <= 32 || str[0] >= 127) && r == 0)
			{
				i++;
				r++;
				continue;
			}
			if (str[i] == ' ')
			{
				i++;
				break;
			}
			strLen++;
			i++;
		}
		strArr[x] = malloc(sizeof(char) * (strLen + 1));
		if (strArr[x] == NULL)
		{
			for (i = 0; i < x; i++)
			{
				free(strArr[i]);
			}
			free(strArr);
			return (NULL);
		}
	}
	initArr(str, strArr, arrSize);
	return (strArr);
}

/**
 * **initArr - Initialize the passed array of strings
 * @str: Is the string which will be used to init the array
 * @strArr: Is the String to initialize with proper data
 * @arrSize: Is the size of the  array strArr
 * Return: void
 */

void initArr(char *str, char **strArr, int arrSize)
{
	int i = 0;
	int r = 0;
	int x = 0;
	int j = 0;
	char cur;
	char next;

	for (x = 0; x < arrSize; x++)
	{
		j = 0;
		while (str[i] != '\0')
		{
			cur = str[i];
			next = str[i + 1];
			if ((cur <= 32 || cur >= 127) && (!(next > 32) || !(next < 127)))
			{
				i++;
				continue;
			}
			else if ((str[0] <= 32 || str[0] >= 127) && r == 0)
			{
				i++;
				r++;
				continue;
			}
			if (str[i] == ' ')
			{
				i++;
				j++;
				break;
			}
			strArr[x][j] = str[i];
			j++;
			i++;
		}
		strArr[x][j] = '\0';
	}
	strArr[x] = NULL;
}
