#include "shell.h"
/**
 * _strcopy - function def
 * @destination: is a variable
 * @origin: is a variable
 * Return: character
 */
char *_strcopy(char *destination, char *origin)
{
	int count = 0;

	if (destination == origin || origin == 0)
		return (destination);
	while (origin[count])
	{
		destination[count] = origin[count];
		count++;
	}
	destination[count] = 0;
	return (destination);
}



/**
 * _puts - function def
 * @strValue: is a string
 *
 * Return: Nothing
 */
void _puts(char *strValue)
{
	int count = 0;

	if (!strValue)
		return;
	while (strValue[count] != '\0')
	{
		_putchar(strValue[count]);
		count++;
	}
}

/**
 * _putchar - function def
 * @charVal: is a variable
 * Return: int
 */
int _putchar(char charVal)
{
	static int count;
	static char buf[BUFSIZEWRITE];

	if (charVal == FLUSHBUF || count >= BUFSIZEWRITE)
	{
		write(1, buf, count);
		count = 0;
	}
	if (charVal != FLUSHBUF)
		buf[count++] = charVal;
	return (1);
}
/**
 * _strdupcase - function def
 * @strValue: is a variable
 *
 * Return: character
 */
char *_strdupcase(const char *strValue)
{
	int length = 0;
	char *ret;

	if (strValue == NULL)
		return (NULL);
	while (*strValue++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--strValue;
	return (ret);
}


