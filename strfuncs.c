#include "main.h"
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
 * *_strcpy - copies one script into another
 *
 * @dest: destination script
 * @src: main script to be copied
 *
 * Return: returns the destination script
 */
char *_strcpy(char *dest, char *src)
{
	int a = 0;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a++] = '\0';

	return (dest);
}

/**
 * *_strchr - function that locates a character in a string
 *
 * @s: string presented
 * @c: character to be checked for
 *
 * Return: returns the first occurence of the character
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);

	return ('\0');
}

/**
 * _strspn - function that gets the length of a prefix substring
 *
 * @s: string to be checked
 * @accept: prefix to accept
 *
 * Return: the length of the prefix substring
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, k = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (k != i)
			break;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				k++;
		}
	}

	return (k);
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
