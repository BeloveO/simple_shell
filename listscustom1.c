#include "shell.h"

/**
 * listToStr - function def
 * @firstDef: is a variable
 * Return: char
 */
char **listToStr(list_t *firstDef)
{
	list_t *node = firstDef;
	size_t i = listLength(firstDef), j;
	char **strValues;
	char *strVal;

	if (!firstDef || !i)
		return (NULL);
	strValues = malloc(sizeof(char *) * (i + 1));
	if (!strValues)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		strVal = malloc(_strlength(node->str) + 1);
		if (!strVal)
		{
			for (j = 0; j < i; j++)
				free(strValues[j]);
			free(strValues);
			return (NULL);
		}

		strVal = _strcopy(strVal, node->str);
		strValues[i] = strVal;
	}
	strValues[i] = NULL;
	return (strValues);
}

/**
 * listLength - function def
 * @first: is a variable
 * Return: sizet
 */
size_t listLength(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}

/**
 * printList - function def
 * @first: pointer to first node
 *
 * Return: size of list
 */
size_t printList(const list_t *first)
{
	size_t i = 0;

	while (first)
	{
		_puts(convertnum(first->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(first->str ? first->str : "(nil)");
		_puts("\n");
		first = first->next;
		i++;
	}
	return (i);
}
/**
 * getNodeAtIndex - function def
 * @first: is a variable
 * @node: is a pointer
 *
 * Return: sizet
 */
ssize_t getNodeAtIndex(list_t *first, list_t *node)
{
	size_t i = 0;

	while (first)
	{
		if (first == node)
			return (i);
		first = first->next;
		i++;
	}
	return (-1);
}

/**
 * nodeStartWith - function def
 * @node: is a variable
 * @valMatch: is a variable
 * @charVal: is a variable
 *
 * Return: match node or null
 */
list_t *nodeStartWith(list_t *node, char *valMatch, char charVal)
{
	char *pointer = NULL;

	while (node)
	{
		pointer = startwith(node->str, valMatch);
		if (pointer && ((charVal == -1) || (*pointer == charVal)))
			return (node);
		node = node->next;
	}
	return (NULL);
}



