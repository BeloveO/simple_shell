#include "shell.h"
/**
 * print_alias - function def
 * @node: node def
 *
 * Return: 0
 */
int print_alias(list_t *node)
{
	char *pointer = NULL, *list = NULL;

	if (node)
	{
		pointer = _strchar(node->str, '=');
		for (list = node->str; list <= pointer; list++)
		_putchar(*list);
		_putchar('\'');
		_puts(pointer + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * unset_alias - is a variable
 * @varInfo: is a variable
 * @str: string variable
 *
 * Return: 0
 */
int unset_alias(info_t *varInfo, char *str)
{
	char *pointer, charVal;
	int retVal;

	pointer = _strchar(str, '=');
	if (!pointer)
		return (1);
	charVal = *pointer;
	*pointer = 0;
	retVal = deleteNodeAtIndex(&(varInfo->alias),
		getNodeAtIndex(varInfo->alias, nodeStartWith(varInfo->alias, str, -1)));
	*pointer = charVal;
	return (retVal);
}
/**
 * set_alias - function def
 * @varInfo: var info variable
 * @str: variable string
 *
 * Return: -
 */
int set_alias(info_t *varInfo, char *str)
{
	char *p;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(varInfo, str));

	unset_alias(varInfo, str);
	return (addNodeEnd(&(varInfo->alias), str, 0) == NULL);
}
/**
 * _ouralias - function def
 * @varInfo: info variable
 * Return: int
 */
int _ouralias(info_t *varInfo)
{
	int count = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (varInfo->argc == 1)
	{
		node = varInfo->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (count = 1; varInfo->argv[count]; count++)
	{
		p = _strchar(varInfo->argv[count], '=');
		if (p)
			set_alias(varInfo, varInfo->argv[count]);
		else
			print_alias(nodeStartWith(varInfo->alias, varInfo->argv[count], '='));
	}

	return (0);
}


/**
 * _ourhistory - function def
 * @varInfo: is a variable
 *  Return: int
 */
int _ourhistory(info_t *varInfo)
{
	printList(varInfo->history);
	return (0);
}









