#include "shell.h"

/**
 **_strnconcatenate - function def
 *@settle: is a variable
 *@origin: is a variable
 *@n: is a variable
 *Return: char
 */
char *_strnconcatenate(char *settle, char *origin, int n)
{
	int count, count2;
	char *s = settle;

	count = 0;
	count2 = 0;
	while (settle[count] != '\0')
		count++;
	while (origin[count2] != '\0' && count2 < n)
	{
		settle[count] = origin[count2];
		count++;
		count2++;
	}
	if (count2 < n)
		settle[count] = '\0';
	return (s);
}

/**
 **_strchar - function def
 *@str: is a variable
 *@charVal: is a variable
 *Return: char
 */
char *_strchar(char *str, char charVal)
{
	do {
		if (*str == charVal)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

/**
 **_strncopy - function def
 *@settle: is a variable
 *@origin: is a variable
 *@n: is a variable
 *Return: char
 */
char *_strncopy(char *settle, char *origin, int n)
{
	int count, count2;
	char *s = settle;

	count = 0;
	while (origin[count] != '\0' && count < n - 1)
	{
		settle[count] = origin[count];
		count++;
	}
	if (count < n)
	{
		count2 = count;
		while (count2 < n)
		{
			settle[count2] = '\0';
			count2++;
		}
	}
	return (s);
}
