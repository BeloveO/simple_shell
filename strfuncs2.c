#include "main.h"
/**
 * _strlen - checking for the length of a string
 * @s: string to be checked
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
 * _isdigit - checks if input is a digit
 * @c: input to be checked
 * Return: 1 if input is digit and 0 if otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * _strdup - duplicate a string in the memory
 * @s: pointer to the string
 * Return: duplicated string
*/
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
  * rev_string - Reverses a string
  * @s: The string to be modified
  */
void rev_string(char *s)
{
	int i, c = 0, k;
	char *a, aux;

	a = s;

	while (s[c] != '\0')
	{
		c++;
	}
	for (i = 0; i < (c - 1); i++)
	{
		for (k = i + 1; k > 0; k--)
		{
			aux = *(a + k);
			*(a + k) = *(a + (k - 1));
			*(a + (k - 1)) = aux;
		}
	}
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string
 * @delim: delimiter
 * Return: 1 if are equals, 0 if not
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}
