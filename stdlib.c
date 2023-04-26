#include "main.h"
/**
 * get_len - Get the length of a number.
 * @n: type int number.
 * Return: Length.
 */
int get_len(int n)
{
	unsigned int i;
	int len = 1;

	if (n < 0)
	{
		len++;
		i = n * -1;
	}
	else
	{
		i = n;
	}
	while (i > 9)
	{
		len++;
		i = i / 10;
	}

	return (len);
}

/**
 * _itoa - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *_itoa(int n)
{
	unsigned int i;
	int len = get_len(n);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (n < 0)
	{
		i = n * -1;
		buffer[0] = '-';
	}
	else
	{
		i = n;
	}

	len--;
	do {
		*(buffer + len) = (i % 10) + '0';
		i = i / 10;
		len--;
	}
	while (i > 0)
		;
	return (buffer);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}

		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}

		if (isi == 1)
		{
			break;
		}

		c++;
	}

	ni *= min;
	return (ni);
}
