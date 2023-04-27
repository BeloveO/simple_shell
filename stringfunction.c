#include "shell.h"
/**
 * _strconcatenate - function def
 * @destination: is a variable
 * @origin: is the origin
 * Return: pointer to destinationination buffer
 */
char *_strconcatenate(char *destination, char *origin)
{
	char *retVal = destination;

	while (*destination)
		destination++;
	while (*origin)
		*destination++ = *origin++;
	*destination = *origin;
	return (retVal);
}

/**
 * _strcompare - function def
 * @str1: is a variable
 * @str2: the second strang
 * Return: int
 */
int _strcompare(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * _strlength - function def
 * @str: is a variable
 * Return: count
 */
int _strlength(char *str)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str++)
		count++;
	return (count);
}





/**
 * startwith - function def
 * @varOne: is a variable
 * @varTwo: is a variable
 * Return: char
 */
char *startwith(const char *varOne, const char *varTwo)
{
	while (*varTwo)
		if (*varTwo++ != *varOne++)
			return (NULL);
	return ((char *)varOne);
}