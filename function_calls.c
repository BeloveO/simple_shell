#include "main.h"

/**
 * _strdup - function to duplicate a string
 * @str: string to be duplicated
 * Return: duplicated string
*/
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;  /* Add 1 for terminating null byte */
	char *newstr = malloc(len);

	if (newstr == NULL)
	{
		return (NULL);  /* Memory allocation failed */
	}
	_memcpy(newstr, str, len);  /* Copy the string to new memory location */
	return (newstr);
}

/**
 * _strncmp - function to compare a certain number of characters of 2 strings
 * @s1: string to be compared
 * @s2: string to be compared
 * @n: number of characters to be compared
 * Return: success(0)
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			/* End of string s1 reached before n characters */
			return (0);
		}
	}
	return (0);
}

/**
 * _strlen - checking for the length of a string
 *
 * @s: string to be checked
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - function to compare two strings
 *
 * @s1: one of the strings to be compared
 * @s2: second string to be compared
 *
 * Return: 0 if they are equal and another number if not
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * *_strcat - function to concatenate two strings
 *
 * @dest: first string
 * @src: second string
 *
 * Return: returns concatenated string (dest)
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i]  = '\0';

	return (dest);
}
