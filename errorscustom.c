#include "shell.h"

/**
 * _eputsfunc - function def
 * @str: is a string var
 *
 * Return: Nothing
 */
void _eputsfunc(char *str)
{
	int count = 0;

	if (!str)
		return;
	while (str[count] != '\0')
	{
		_eputcharacter(str[count]);
		count++;
	}
}

/**
 * _putsfd - function def
 * @str: is a string
 * @fileVal: is a variable
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fileVal)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fileVal);
	}
	return (i);
}

/**
 * _eputcharacter - function def
 * @charVar: The character to print
 *
 * Return: 1
 */
int _eputcharacter(char charVar)
{
	static int count;
	static char buf[BUFSIZEWRITE];

	if (charVar == FLUSHBUF || count >= BUFSIZEWRITE)
	{
		write(2, buf, count);
		count = 0;
	}
	if (charVar != FLUSHBUF)
		buf[count++] = charVar;
	return (1);
}

/**
 * _putfd - function def
 * @charVar: is a variable
 * @fileVal: is a variable
 *
 * Return: 1
 */
int _putfd(char charVar, int fileVal)
{
	static int count;
	static char buf[BUFSIZEWRITE];

	if (charVar == FLUSHBUF || count >= BUFSIZEWRITE)
	{
		write(fileVal, buf, count);
		count = 0;
	}
	if (charVar != FLUSHBUF)
		buf[count++] = charVar;
	return (1);
}



