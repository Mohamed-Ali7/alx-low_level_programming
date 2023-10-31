#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char *strFilter(char *s);
/**
 * **strtow - splits a string into words.
 * @str: Is the string to split
 * Return: A pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **strArr;
	int arrSize = 1;
	int strLen = 0;
	int i;
	int r = 0;
	char *fltStr;
	int x = 0;

	if (str == NULL || str[0] == '\0')
	{
		return (NULL);
	}
	fltStr = strFilter(str);
	for (i = 0; fltStr[i] != '\0'; i++)
	{
		if (fltStr[i] == ' ')
		{
			arrSize++;
		}
	}
	strArr = malloc(sizeof(char *) * arrSize);
	if (strArr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < arrSize; i++)
	{
		strLen = 0;
		while (fltStr[r] != '\0' && fltStr[r] != ' ')
		{
			strLen++;
			r++;
		}
		r++;
		strArr[i] =  malloc(sizeof(char) * (strLen + 1));
		if (strArr[i] == NULL)
		{
			return (NULL);
		}
	}
	r = 0;
	for (i = 0; i < arrSize; i++)
	{
		x = 0;
		while (fltStr[r] != '\0' && fltStr[r] != ' ')
		{
			strArr[i][x] = fltStr[r];
			r++;
			x++;
		}
		r++;
		strArr[i][x] = '\0';
	}
	strArr[i] = NULL;
	return (strArr);
}
/**
 * *strFilter - Filters a string by removing all un printable characters
 * @s: Is the string to filter
 * Return: A pointer to the new filtered string
 */
char *strFilter(char *s)
{
	int i = 0;
	int r = 0;
	int strSize = 0;
	char cur;
	char next;
	char *filteredStr;

	for (i = 0; s[i] != '\0'; i++)
	{
		cur = s[i];
		next = s[i + 1];
		if ((cur <= 32 || cur >= 127) && (!(next > 32) || !(next < 127)))
		{
			continue;
		}
		else if ((s[0] <= 32 || s[0] >= 127) && r == 0)
		{
			r++;
			continue;
		}
		strSize++;
	}
	filteredStr = malloc(sizeof(char) * strSize + 1);
	r = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		cur = s[i];
		next = s[i + 1];
		if ((cur <= 32 || cur >= 127) && !((next > 32) || !(next < 127)))
		{
			continue;
		}
		if ((cur <= 32 || cur >= 127) && r == 0)
		{
			continue;
		}
		filteredStr[r] = cur;
		r++;
	}
	return (filteredStr);
}
