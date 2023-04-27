#include "shell.h"

/**
 * _setenv - function definition
 * @varInfo: is a variable
 * @charVal: is a variable
 * @retVal: is a variable
 *  Return: Always 0
 */
int _setenv(info_t *varInfo, char *charVal, char *retVal)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!charVal || !retVal)
		return (0);

	buf = malloc(_strlength(charVal) + _strlength(retVal) + 2);
	if (!buf)
		return (1);
	_strcopy(buf, charVal);
	_strconcatenate(buf, "=");
	_strconcatenate(buf, retVal);
	node = varInfo->env;
	while (node)
	{
		p = startwith(node->str, charVal);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			varInfo->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	addNodeEnd(&(varInfo->env), buf, 0);
	free(buf);
	varInfo->env_changed = 1;
	return (0);
}

/**
 * _unsetenv - function def
 * @varInfo: is a variable
 * @charVal: isa variable
 *  Return: 1
 */
int _unsetenv(info_t *varInfo, char *charVal)
{
	list_t *node = varInfo->env;
	size_t i = 0;
	char *p;

	if (!node || !charVal)
		return (0);

	while (node)
	{
		p = startwith(node->str, charVal);
		if (p && *p == '=')
		{
			varInfo->env_changed = deleteNodeAtIndex(&(varInfo->env), i);
			i = 0;
			node = varInfo->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (varInfo->env_changed);
}

/**
 * get_environ - function def
 * @varInfo: is a variable
 * Return: 0
 */
char **get_environ(info_t *varInfo)
{
	if (!varInfo->environ || varInfo->env_changed)
	{
		varInfo->environ = listToStr(varInfo->env);
		varInfo->env_changed = 0;
	}

	return (varInfo->environ);
}


