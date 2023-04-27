#include "shell.h"

/**
 * is_delimitor - function def
 * @charVal: is a variable
 * @delimitor: is a varialbe
 * Return: 1
 */
int is_delimitor(char charVal, char *delimitor)
{
	while (*delimitor)
		if (*delimitor++ == charVal)
			return (1);
	return (0);
}

/**
 * _atoi - function def
 * @str: is a string
 * Return: 0
 */

int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * interactive - function def
 * @varInfo: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *varInfo)
{
	return (isatty(STDIN_FILENO) && varInfo->readfd <= 2);
}

/**
 * _isalphabet - function def
 * @charVar: is a char value
 * Return: 1
 */

int _isalphabet(int charVar)
{
	if ((charVar >= 'a' && charVar <= 'z') || (charVar >= 'A' && charVar <= 'Z'))
		return (1);
	else
		return (0);
}
