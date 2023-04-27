#include "main.h"

/**
 * _strtok - function to tokenize strings
 * @str: string to be tokenized
 * @delim: delimiter to separate strings
 * Return: token
*/
char *_strtok(char *str, const char *delim)
{
	static char *last_token;  /* Pointer to last token found */
	char *token = NULL;
	int i, j, k, found;

	if (str == NULL)
		str = last_token;
	for (i = 0; str[i] != '\0'; i++)
	{
		found = 0; for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
	}
	if (str[i] == '\0')
	{
		last_token = NULL;
		return (NULL);
	} for (j = i + 1; str[j] != '\0'; j++)
	{
		found = 0; for (k = 0; delim[k] != '\0'; k++)
		{
			if (str[j] == delim[k])
			{
				found = 1;
				break;
			}
		}
		if (found)
			break;
	} token = (char *) malloc(sizeof(char) * (j - i + 1));
	_strncpy(token, &str[i], j - i);
	token[j - i] = '\0';
	last_token = &str[j];
	return (token);
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
 * *_memcpy - function that copies memory area
 *
 * @dest: new copy destination
 * @src: source of copy
 * @n: number of elements to be copied
 *
 * Return: new copied file (dest)
 */
char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * *_strncpy - function to copy the contents of one string to another
 *
 * @dest: string to be copied into
 * @src: string to be copied
 * @n: the number the string will be copied to
 *
 * Return: returns the copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
